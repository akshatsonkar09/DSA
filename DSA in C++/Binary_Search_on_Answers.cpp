#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int Sqrt_of_int_using_binary_search(int N) {
    //This is a simple question of using the binary search code
    int low = 1, high = N, mid, ans = 1;
    while (low <= high)
    {
        mid = (high-low)/2;
        if(mid*mid >= N) high = mid - 1;
        else {low = mid + 1;
        ans = mid;
    }
    return ans;
    }
    
}
int main() {
    
    return 0;
}