#include <stdio.h>

void qsort(int array[], int s, int t)
{
	if (s < t) {
		int p = partition(array, s, t);
		qsort(array, s, p - 1);
		qsort(array, p + 1, t);
	}
}

int partition(int array[], int low, int high)
{
	int temp = array[low];

	while (low < high) {
		while (low < high && array[high] >= temp)
			high--;
		array[low] = array[high];
		while (low < high && array[low] <= temp)
			low++;
		array[high] = array[low];
	}
	array[low] = temp;

	return low;
}

int main()
{
	int i;
	int arr[] = { 0, 2, 0, 3, 2, 9, 4, 5, 7, 7 };
	qsort(arr, 0, 9);
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
