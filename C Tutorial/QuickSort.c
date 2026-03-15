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








int partition(int *A, int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    while (i < j);
    temp = A[j];
    A[j] = A[low];
    A[low] = temp;
    return j;




    /*This entire if is not needed WHY?*/

    // if (i > j)
    // {
    //     temp = A[j];
    //     A[j] = A[low]; // A[low] is used instead of pivot because pivot is a local variable while we need changes in actual array
    //     A[low] = temp;
    //     return temp;
    //     ;
    // }

    /*1) the do … while (i < j) loop runs until i >= j. That means when you break out, you already know i > j (or i == j). There’s no need to check if (i > j) again — it’s guaranteed.*/
}









void quicksort(int *A, int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        printarray(A,5);
        quicksort(A, low, partitionIndex - 1);  // Sort Left to Pivot
        quicksort(A, partitionIndex + 1, high); // Sort Right to Pivot
    }
}





int main()
{

    int A[] = {2, 16, 4, 12, 7};
    int n = sizeof(A) / sizeof(int); // Way to write no. of elements in array
    printarray(A, n);
    quicksort(A, 0, n - 1);
    printarray(A, n);

    return 0;
}