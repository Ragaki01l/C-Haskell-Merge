#include <stdio.h>

#define max 10

int arr[] = {4, 65, 2, -31, 0, 99, 2 ,83, 782, 1};

int main()
{
    int arrsize = sizeof(arr);
    int arrpoint = &arr;

    msort(arrpoint, arrsize);
}

void msort(int *a, int n)
{
    int low,mid;

    low = 0;
    mid = (low + n)/2;

    mergeS(*a, low, n);
}


void mergeS(int arr[], int low, int high)
{
    int mid = (low + high)/2;

    if(low < high)
    {
        mergeS(arr, low, mid);
        mergeS(arr, mid + 1, high);
        arraymerge( low, mid, high, arr);
    }

}


void arraymerge(int low, int mid, int high, int arr[])
{
    int temp[max]; //initialize temp array

    int i = low; //start of 1st array
    int mid2 = mid + 1; //start of 2nd array
    int start = 0;

    while(i <= mid && mid2 <= high) //Sorts array and puts them into respective lists
    {
        if(arr[i] < arr[mid2])
            temp[start++] = arr[i++];
        else
            temp[start++] = arr[mid2++];
    }

    while(i <= mid) //Gets remaining numbers from 1st array
    {
        temp[start++] = arr[i++];
    }

    while (mid2 <= high) //Gets remaining numbers from 2nd array
    {
        temp[start++] = arr[mid2++];
    }

    for(i = low, mid2 = 0; i <= high; i++, mid2++) //Puts numbers back into array
    {
        arr[i] = temp[mid2++];
    }
}