#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int m, int size) {
    int i,j,k=0;
    int A1[m],A2[size-m];
    
    for (i=0; i < m; i++) A1[i] = arr[k++];
    for (i=m; i < size; i++) A2[i-m] = arr[k++];

    i=0;j=0;k=0;
    while (i < m && j < (size-m)) {
        if (A1[i] <= A2[j]) arr[k++] = A1[i++];
        else arr[k++] = A2[j++];
    }

    while (i < m) arr[k++] = A1[i++];
    while (j < (size-m)) arr[k++] = A2[j++];
}

void mergeSort(int *arr, size_t size) {
    if (size < 2) return;

    int m = size/2;

    mergeSort(arr, m);
    mergeSort(arr, size-m);
    merge(arr, m, size);
}

void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main(void) {
	int arr[] = { 12, 11, 13, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);

	mergeSort(arr, arr_size);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}
