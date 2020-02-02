#include <stdio.h>
#define max 9

int arr[] = {4, 65, 2, -31, 0, 99, 2 ,83, 782, 1}; //Initialize array to be sorted


//Initialize all functions to be used
void mergeS(int *arr, int low, int high);
void arraymerge(int low, int mid, int mid2 ,int high, int arr[]);
void msort(int *a, int n);

void arraymerge(int low, int mid, int mid2, int high, int arr[])
{
    int temp[max]; //initialize temp array

    int i = low; //start of 1st array
    int i2 = mid2; //start of 2nd array
    int start = 0;

    while(i <= mid && i2 <= high) //Sorts array and puts them into respective lists
    {
        if(arr[i] < arr[i2])
           {
            temp[start++] = arr[i++];
           }
        else
            temp[start++] = arr[i2++];
    }

    while(i <= mid) //Gets remaining numbers from 1st array
    {
        temp[start++] = arr[i++];
    }

    while (i2 <= high) //Gets remaining numbers from 2nd array
    {
        temp[start++] = arr[i2++];
    }

    for(int i = low, i2 = 0; i <= high; i++, i2++) //Puts numbers back into original array
    {
        arr[i] = temp[i2];
        
    }
}


void mergeS(int arr[], int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = (low + high)/2; //Calculates the middle index of the array
        mergeS(arr, low, mid); //Recursion on left side of tree
        mergeS(arr, mid + 1, high); //Recursion on righy side of tree
        arraymerge( low, mid, mid + 1, high, arr); //Array merging
    }

}

//Wrapper class of merge sort
void msort(int *a, int n)
{
    //Determines the beginning of the the array
    int low;
    low = 0;

    //Passes array, low, and size - 1 of array through proper function
    mergeS(a, low, n - 1);
}

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
