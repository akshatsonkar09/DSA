#include <stdio.h>

int sum_of_odd_number(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0) continue;
        if (i % 3 == 0) continue;
        sum += i;
        if (sum > 50)
            break;
    }
    return sum;
}

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int ans = sum_of_odd_number(n);
    printf("Sum = %d\n", ans);

    return 0;
}