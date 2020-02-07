#include <stdio.h>
#define max 10

int arr[] = {4, 65, 2, -31, 0, 99, 2 ,83, 782, 1}; //Initialize array to be sorted

//Inititalize functions
void swapElement(int *a, int *b);
void qsort2(int *a, int n);
void qsort(int arr[], int low, int high);
int partition(int arr[], int low, int high);


//Simple swap function
void swapElement(int *a, int *b){
    //printf("Swap has occured");
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    
    int pElement = arr[high]; //Element index to be pivoted
    int smallElement = low - 1;  //Index of the lesser element
    //printf("test");

    for(int index = low; index <= high; index++){
        
        //Trigger if current index is less
        if(arr[index] < pElement){
            smallElement++;
            swapElement(&arr[smallElement], &arr[index]);
        }
    }

    swapElement(&arr[smallElement + 1], &arr[high]);
    return(smallElement + 1);
}

//Main qsort function, recursively calls itself on both halves of main arr
void qsort(int arr[], int low, int high){

    if(low < high)
    {
        int partitionIndex = partition(arr, low, high);

        qsort(arr, low, partitionIndex - 1); //Quick Sorts on the left side of the array
        qsort(arr, partitionIndex + 1, high); //Quick Sorts on the right side of thearray
        
    }
}

//Wrapper class for quicksort
void qsort2(int *a, int n){
    //Determines the low end of the array
    int low;
    low = 0;

    //Calls qsort function
    qsort(a, low, n - 1);
}

int main()
{
    printf("Unsorted array is : ");

    for(int i = 0; i < max; i++){
        printf("%d : ", arr[i]);
    }

    qsort2(arr, max);

    printf("\nSorted array is : ");

    for(int j = 0; j < max; j++){
        printf("%d : ", arr[j]);
    }
}
