#include <stdio.h>
#include <stdlib.h>

int main() {

    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        int val = i;
        int add = n-1;

        for (int j = 1; j <= i; j++)
        {
            printf("%d ", val);
            val += add;
            add--;
        }
        printf("\n");
        
    }
    
return 0;
}