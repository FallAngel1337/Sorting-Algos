#include <stdio.h>

#define SWAP(a,b)((a)^=(b),(b)^=(a),(a)^=(b))

unsigned list[] = {6, 7, 3, 5, 8, 9, 0, 2, 1, 4};
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

int main(void) 
{
    bubbleSort(list, 10);
    
    for (int i=0; i < 10; i++) {
        printf("list[%d] = %d\n", i, list[i]);
    }

    return 0;
}
