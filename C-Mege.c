int main()
{
    int arr[] = {4, 65, 2, -31, 0, 99, 2 ,83, 782, 1};
    int arrsize = sizeof(arr);
}

void msort(init *a, int n)
{
    int low,mid;

    low= 0;
    mid = (low + n)/2;

    if(low < n)
    {
        msort(low,mid); //recursion on left side of tree
        msort(mid + 1, n); //recursion on right side of tree
        arraymerge(low, mid, n, *a);
    }
}

void arraymerge(int low, int mid, int high, int *a)
{
    int temp[high- 1]; //initialize temp array

    int mid2 = mid + 1;
    int = low;

    for(low, mid2, i; low <= mid && mid2 <= high, i++)
    {
        
    }
}