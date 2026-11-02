#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//In this question both decrementing single value and incrementing n-1 values gives same gaps
//Answer is the difference between the nums[i] with minimum element


class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mini = *min_element(nums.begin(), nums.end());
        long long sum = accumulate(nums.begin(),nums.end(),0LL);

        return sum-n*mini;
    }
};

int main() {

    

    return 0;
}