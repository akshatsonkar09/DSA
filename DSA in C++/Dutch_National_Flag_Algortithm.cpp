#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void Dutch_National_Flag_Algo(vector <int> &nums) {
    int n = nums.size();
    int low = 0, mid = 0, high = n-1;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid],nums[high]);
            high--;
        }
    }
}

int main() {
    
    vector <int> nums  = {0,1,0,2,1,2,0,1,2,0,0,1,2,2};
    Dutch_National_Flag_Algo(nums);
    for (auto i: nums)
    {
       cout << i << " ";
    }
    cout << endl;

    return 0;
}