#include <stdio.h>

unsigned long shellsort(char *a[], int n)
{
	unsigned long ccount = 0;
	unsigned long mcount = 0;
	int i, j, gap;
	char *temp;

	for (gap = n/2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++)
			for (j=i-gap; j>=0 && ccount++ && strcmp(a[j], a[j+gap])>0; j-=gap) {
				mcount++;
				temp = a[j];
				a[j] = a[j+gap];
				a[j+gap] = temp;
			}

	return ccount + mcount;
}
