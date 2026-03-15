
#include <stdio.h>
#include <stdlib.h>

int main() {

    int row1m = 3,col1n = 2,row2n = 2,col2m =3;

    if (row2n != col1n)
    {
        printf("Not a valid Matrix Multiplication");
    }

    else
    {
        int **A = malloc(row1m*(sizeof(int*)));
        int **B = malloc(row2n*(sizeof(int*)));
        int **C = malloc(row1m*(sizeof(int*)));

        for( int i = 0; i < row1m; i++) {
            A[i] = calloc(col1n,sizeof(int));
        }

        for( int i = 0; i < row1m; i++) {
            B[i] = calloc(col2m,sizeof(int));
        }

        for( int i = 0; i < row1m; i++) {
            C[i] = calloc(col2m,sizeof(int));
        }


        for(int i = 0; i < row1m; i++) {
            for (int j= 0;j < col1n; j++) {
            scanf("%d", &A[i][j]);
            }
        }


        for (int i = 0; i < row2n; i++)
        {
            for (int j = 0; i < col2m; i++)
            {
                scanf("%d", &B[i][j]);
            }
        }

        for(int i = 0; i < row1m; i++) {
            for(int j = 0; j< col2m; i++) {
                for ( int k = 0; k < col1n ;k++) {
                    C[i][j] += A[i][k] + B[k][j];
                }
            }
        }
        


    }
    
    

return 0;
}
