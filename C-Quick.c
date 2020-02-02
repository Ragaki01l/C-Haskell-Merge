#include <stdio.h>
#define max 9

int arr[] = {4, 65, 2, -31, 0, 99, 2 ,83, 782, 1}; //Initialize array to be sorted

int main()
{
    printf("Unsorted array is : ");

    for(int i = 0; i < max; i++){
        printf("%d : ", arr[i]);
    }

    msort(arr, max);

    printf("\nSorted array is : ");

    for(int j = 0; j < max; j++){
        printf("%d : ", arr[j]);
    }
}
