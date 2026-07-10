#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0 || x == 1) return x;

        int low = 1, high = x;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;

            long long square = (long long)mid * (long long)mid;

            if (square == x) return mid;
            else if (square > x) high = mid - 1;
            else low = mid + 1;
        }

        return high;
    }
};

int main()
{
    return 0;
}