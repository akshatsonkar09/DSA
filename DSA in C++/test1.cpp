#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        int ans = 2;
        //Xor cannot create new bit hence for if n = 4 then only 3 bits so answer has to a 3 bit value and by hit and trial we can determine that it will have all the value from 0 to 2^n-1 values
        //Basically agar 3 bit hi hai 1,2,3,4 to 7 me toh 4 bit wala number ban hi nahi sakta hai

        while (n != 1)
        {
            n /= 2;
            ans *= 2;
        }
        return ans;
    }
};



int main()
{
    return 0;
}