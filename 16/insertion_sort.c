#include <stdio.h>

int insertion_sort(int array[], int n)
{
	int i, j;
	int key;

	for (i = 1; i < n; i++) {
		key = array[i];
		j = i - 1;
		while (j >= 0 && key < array[j]) {
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = key;
	}

	return 0;
}

int main()
{
	int i;
	int a[] = {2, 1, 4, 4, 3};

	insertion_sort(a, 5);
	for (i = 0; i < sizeof(a)/sizeof(int); i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}
