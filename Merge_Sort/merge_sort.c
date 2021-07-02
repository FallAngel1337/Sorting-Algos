#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int s, int m, int e) 
{
    int tmp[e-s];
    int i=s,j=m+1,k=0;

    while (i <= m && j <= e)
    {
        if (arr[i] <= arr[j]) tmp[k++] = arr[i++];
        else tmp[k++] = arr[j++];
    }

    while (i <= m) tmp[k++] = arr[i++];
    while (j <= e) tmp[k++] = arr[j++];

    k--;
    while (k >= 0) {
        arr[s + k] = tmp[k];
        k--;
    }
}

void mergeSort(int *arr, int __start, int __end)
{
    if (__start < __end) {
        int mid = (__start + __end)/2;
        mergeSort(arr, __start, mid);
        mergeSort(arr, mid+1, __end);
        merge(arr, __start, mid, __end);
    }
}


void printArray(int *arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(void) {
    int list[] = {6, 7, 3, 5, 8, 9, 0, 2, 1, 4, 1, 6, 4, 3, 3, 7, 100, 8, 9, 9, 0, 3, 4, 6, 7, 8, 1, 99};
    size_t list_len = sizeof(list)/sizeof(list[0]);
    printf("MergeSort Algo!\n");

	printf("Before:\n");
	printArray(list, list_len);

	mergeSort(list, 0, list_len-1);
	
    printf("After:\n");
	printArray(list, list_len);
	return 0;
}
