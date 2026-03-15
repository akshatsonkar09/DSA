#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void printarray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d", A[i]);
    }
    printf("\n");
}


int maximum(int A[], int n) {
    int max = INT_MIN;  // This is from include limits
    for (int i =  0; i < n; i++){
        if (max < A[i]) {
            max = A[i];
        }
    }
    return max;
}


void countSort (int* A, int n) {
    int i,j;

    int max = maximum(A,n); //Find maximum element in A 

    int* count = (int*) malloc((max+1)*sizeof(int));    // Creation of count array

    for (int i = 0; i <n; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        count[A[i]]++;
    }
    
    i = 0;
    j = 0;

    while (i <= max)
    {
        if (count[i]>0)
        {
            A[j] = i;
            count[i]--;
            j++;
        }
        else
        {
            i++;
        }
    }
    
}

int main() {
    int A[] = {9,1,4,14,54,23,4};
    int n = sizeof(A)/sizeof(int);
    printarray(A,n);
    countSort(A,n);
    printarray(A,n);

return 0;
}