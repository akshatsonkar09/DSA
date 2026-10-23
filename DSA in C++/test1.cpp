#include <bits/stdc++.h>

class Solution
{
public:
    long long sumAndMultiply(int n)
    {
        long long x = 0, sum = 0;
        int i = 0;

        while (n > 0)
        {
            if (n%10 != 0)
            {
                long long val = n % 10;
                long long place = pow(10, i);
                x += val * place;
                sum += val;
                i++;
            }
            n /= 10;
        }
        return x*sum;
    }
};