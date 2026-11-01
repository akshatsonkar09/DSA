#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        set<int> st;

        for (int i = 0; i < n; i++)
        {
            st.insert(nums[i]);
        }

        int ans = INT_MIN;
        for(auto x:st) {
            if(x != INT_MIN && st.find(x-1) == st.end()) {
                int csct = 1;
                int currnum = x;
                while (st.find(currnum+1) != st.end())
                {
                    currnum++;
                    csct++;
                }
                ans = max(ans,csct);
            }
            
        }
        return ans;
    }
};

int main() {

    

    return 0;
}