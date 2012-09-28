#include <stdio.h>

unsigned long shellsort(int a[], int n)
{
	unsigned long ctimes = 0;
	unsigned long mtimes = 0;
	int i, j, gap;
	int temp;

	for (gap = n/2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++)
			for (j=i-gap; j>=0 && (ctimes++, a[j] > a[j+gap]); j-=gap) {
				mtimes++;
				temp = a[j];
				a[j] = a[j+gap];
				a[j+gap] = temp;
			}

	return ctimes + mtimes;
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
