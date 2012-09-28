#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int count = 0;

int bin_search(char **words, char *word, int n)
{
	int low = 0;
	int high = n;
	int mid;
	int cond;

	while(low <= high) {
		count++;
		mid = (low + high) / 2;
		cond = strcmp(words[mid], word);
		if (cond < 0)
			low = mid + 1;
		else if (cond > 0)
			high = mid - 1;
		else
			return mid;
	}

	return -1;
}

int main()
{
	int i;
	char **words = (char **)malloc(sizeof(char *) * 100000);

	if (words == NULL) {
		printf("error!\n");
		exit(1);
	}

	for (i = 0; i < 100000; i++) {
		words[i] = (char *)malloc(sizeof(char) * 20);
		if (words[i] == NULL) {
			printf("error!\n");
			exit(1);
		}
	}

	i = 0;
	while (scanf("%s", words[i++]) != EOF)
		;

	for (i = 0; i < 79339; i++)
		printf("%d\n", bin_search(words, words[i], 79338));

	printf("average compared times is %d\n", count/79339);

	return 0;
}
