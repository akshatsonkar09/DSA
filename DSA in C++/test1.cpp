#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || n ==2) return n;
        unordered_set <int> st;
        int pairXor[2048] = {0};
        int tripletXor[2048] = {0};

        //saare possible pair of Xor ko 1 kar diya matlab agar ek value hai jo ki hai 5 jo kisi do number ka xor hai toh usko pairXor[5] =1 kar diya
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pairXor[nums[i]^nums[j]] = 1;
            }
        }

        //j ko traverse kar sakte hai kyunki contraints sirf 1500 tak ki hai isliye 2 power 11 yaani 2046 le liya hai ab check karenge ki j ki kis values par yeh array 1 hai yaani pair exists karta hai aur agar karta hai toh uska nums[i] ke saakth triplet nikaal denge
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2048; j++)
            {
                if(pairXor[j] == -1) continue; 
                tripletXor[j^ nums[i]] = 1;
            }
        }

        int ans = 0;
        
        for (int i = 0; i < 2048; i++)
        {
            ans += tripletXor[i];
        }
        
    } 
};



int main()
{
    return 0;
}