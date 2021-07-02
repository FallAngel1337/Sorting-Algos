#include <stdio.h>
#include <stdlib.h>

#define SWAP(a,b)((a)^=(b),(b)^=(a),(a)^=(b))

unsigned char swapped = 1;

void bubbleSort(unsigned *array, size_t size) 
{
    while (swapped) {
        swapped = 0;

        for (int i=0; i < size-1; i++) {
            if (array[i] > array[i+1]) {
                SWAP(array[i], array[i+1]);
                swapped = 1;
            }
        }
    }
}

void printArray(int *arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(void) 
{
    unsigned list[] = {6, 7, 3, 5, 8, 9, 0, 2, 1, 4, 1, 6, 4, 3, 3, 7, 100, 8, 9, 9, 0, 3, 4, 6, 7, 8, 1, 99};
    size_t list_len = sizeof(list)/sizeof(list[0]);
    printf("BubbleSort Algo!\n");

    printf("Before:\n");
	printArray(list, list_len);

	bubbleSort(list, list_len);
	
    printf("After:\n");
	printArray(list, list_len);

    return 0;
}