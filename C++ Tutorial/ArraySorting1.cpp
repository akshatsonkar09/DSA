#include <iostream>
#include <vector>

using namespace std;


int main() {
vector<int> nums = {0,0,1,1,2,4,5,6,6,7};
        int n = nums.size();
        int i= 1, j = nums[0] ,k=1;
        while(i < nums.size()) {
        if(nums[i] != j) {
        nums[k] = nums[i];
        j= nums[i];
        k++;
        }
        i++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << j << " " << k;
    
    

    
    return 0;
}