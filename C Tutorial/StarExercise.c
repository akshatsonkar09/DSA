#include <stdio.h>

int main()
{
    printf("Hello World\n");
    printf("Star and Reverse Star\n");
    int rows;

    scanf("%d", &rows);


for (int i = 1; i <= rows; i++)
{
    for (int j = 1; j <= i; j++)
    {
        printf("*");
    }
    printf("\n");
    
}

printf("\n");


for (int i = rows; i >= 1; i--)
// for (int i = rows(kahan se start karna hai); i >= 1(Kab tak chalana hai); i--(value ko inc/dec karna hai))
{
    for (int j = 1; j <= i; j++)
    {
        printf("*");
    }
    printf("\n");
    
}

    return 0;
}
