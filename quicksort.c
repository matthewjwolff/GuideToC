#include <stdio.h>
#include "arrays.c"

void swap(int a[], int i, int j) {
    int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void quick_sort(int a[], int low, int high) {
    if(low>=high)
		return;
	int pivot = a[high];
	int swapIndex = low;
	for(int i=low; i<high; i++) {
		if(a[i] < pivot) {
			swap(a, swapIndex, i);
			swapIndex++;
		}
	}
	swap(a, swapIndex, high);
	quick_sort(a, low, swapIndex-1);
	quick_sort(a, swapIndex+1, high);
}

int main(int argc, char **argv)
{
    int array[] = {42,11,23,61,103,2,64};
	printf("Original array: ");
    array_print(array, LENGTH(array));
    printf("\n");
    quick_sort(array, 0, LENGTH(array) - 1);
    printf("Sorted array  : ");
    array_print(array, LENGTH(array));
    printf("\n");
	return 0;
}

