#include <stdio.h>

unsigned long ctimes = 0;
unsigned long mtimes = 0;

unsigned long shellinsert(int array[], int gap, int n)
{
	int i, j;
	int key;

	for (i = 1; i < n; i++) {
		key =  array[i];
		j = i - gap;
		while (j >= 0 && (ctimes++, key < array[j])) {
			mtimes++;
			array[j+gap] = array[j];
			j-=gap;
		}
		array[j+gap] = key;
	}

	return ctimes + mtimes;
}

unsigned long shellsort(int array[], int n)
{
	unsigned long times = 0;
	int gap;

	for (gap = n/2; gap > 0; gap /= 2)
		times += shellinsert(array, gap, n);

	return times;
}

int main()
{

	FILE *fp = fopen("test", "r");
	int arr[100000];
	int i;

	for (i = 0; i < 100000; i++) {
		arr[i] = getc(fp);
	}

	printf("%lu\n", shellsort(arr, 100000));

	return 0;
}
