#include <stdio.h>
#include <stdlib.h>





void printarray (int* A, int n) 
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d", A[i]);
    }
    printf("\n");
}





void selectionsort (int* A, int n)
{
    int indexOfmin, temp;
    for (int i = 0; i <= n-1; i++)
    {
        indexOfmin = i;
        for (int j = i+1 ; j < n; j++)
        { 
            if (A[j] < A[indexOfmin])
            {
                indexOfmin = j;
            }
        } 
                temp = A[i];
                A[i] = A[indexOfmin];
                A[indexOfmin] = temp;
    }
}





int main() {


int A[] = {2, 16, 4, 12, 7};
int n = sizeof(A)/sizeof(int);   // Way to write no. of elements in array
printarray(A,n);

return 0;
}