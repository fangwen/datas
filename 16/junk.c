#include <stdio.h>

int main()
{
	FILE *fp = fopen("test", "r");
	int arr[100000];
	int i;
	for (i = 0; i < 100000; i++) {
		arr[i] = getc(fp);
	}

	for (i = 0; i < 100000; i++) {
		printf("%c\n", arr[i]);
	}	

	return 0;
}
