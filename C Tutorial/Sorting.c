#include <stdio.h>
#include <stdlib.h>
#include <string.h>





void printarray (int* A, int n) 
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d", A[i]);
    }
    printf("\n");
}





void bubblesort(int *A, int n)
{
    int temp;
    int isSorted = 0;       //isSorted value is currently 0
    for (int i = 0; i < n; i++)     //No. of passes
    {
        printf("Working on pass %d\n",i+1);
        isSorted = 1;       // isSorted value is changed to 1 when entering into first loop
        for (int j = 0; j < n-1-i; j++)     //For comparison in each pass
        {
            if (A[j] > A[j+1])      //isSorted value is changed to 0 if this condition is true otherwise remains 1 
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                isSorted = 0;
            }
        }   //Exiting second loop after 1st pass

        if(isSorted) //If if statement is executed then value of isSorted is 0 and 0 is by default false so return statement does not execute and if if statement is  not executed then statement remains 1 anf return statement is executed 
        {
            return;
        } 
    } 
}






void insertionsort (int* A, int n) /*Function of key is weak*/
{
    for (int i = 1; i <= n-1; i++)
    {
        int key,j;
        key = A[i];
        j= i-1;
        while (j >= 0 && A[j] > key)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;       //Without this line, the key would just vanish (overwritten during shifts), and the array would lose one value.
        // So, why do we need A[j+1] = key? Because during the while loop we keep shifting all elements one step right until we find the correct spot for key. After the loop ends, j is one step left of the correct position.
    }
}





int main() {

    
// -1   0   1    2    3   4   
//      5   26  14   84   3 ---> i=1, key=26, j=0



int A[] = {5,26,14,84,3};
// int A[] = {1,2,3,4,5};
int n = 5;

//printf("%d", printarray(A,n));
printarray(A,n);
// bubblesort(A,n);
insertionsort(A,n);
printarray(A,n);

return 0;
}