#include <stdio.h>
#include <stdlib.h>






int linearsearch(int arr[],int size,int element)
{
    //int n = sizeof(array)/sizeof(int);    

    /*When you pass an array to a function in C, it decays into a pointer. So sizeof(arr) gives the size of a pointer (typically 4 or 8 bytes), not the size of the original array. ***VERY IMPORTANT***/

    
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            printf("Element Found at index %d", i);
            return i;
        }   
    }
    return -1;
}






int binarysearch(int arr[],int size,int element) 
{
    int low,mid,high;
    low = 0;
    high = size-1;

    
    while (low <= high)
    {
        mid = (low+high)/2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
}






int main() {

    int arr[] = {3,4,6,13,21,54,67};
    int n = sizeof(arr)/sizeof(int);
    int lsearch = linearsearch(arr,n,26);
    printf("%d\n", lsearch);    //Without this -1 will not show
    int bsearch = binarysearch(arr,n,56);
    printf("%d\n", bsearch);

return 0;
}