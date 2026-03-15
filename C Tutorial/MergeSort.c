#include <stdio.h>
#include <stdlib.h>

void printarray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d", A[i]);
    }
    printf("\n");
}

void merge(int A[], int mid, int low, int high)
{
    int i, j, k, n;
    
    int B[high - low + 1];//Dynamic memory allocation to take B[high-low+1] ie exact size
    i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i<=mid)
    {
        B[k]= A[i];
        k++;
        i++;
    }
     while (j<=high)
    {
        B[k]= A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    
}


void mergesort (int A[], int low, int high)
{
    int mid;
    if (low<high)
    {
        mid = (low + high)/2;
        mergesort (A,low,mid);
        mergesort (A,mid+1,high);
        merge(A,mid,low,high);
    }
}


int main()
{
    int A[] = {2, 16, 4, 12, 7};
    int n = sizeof(A) / sizeof(int); // Way to write no. of elements in array
    printarray(A, n);
    mergesort(A, 0, n - 1);
    printarray(A, n);

    return 0;
}
