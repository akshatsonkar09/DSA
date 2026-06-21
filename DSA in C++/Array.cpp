#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector <int> makeUnion (int arr1[], int arr2[], int n1, int n2) {
    int i,j;
    i = j = 0;

    vector <int> v;

    while (i < n1 && j < n2)
    {
        if(arr1[i]<arr2[j]) {
            if (v.empty() || v.back() != arr1[i])
            v.push_back(arr1[i]);
            i++;
        }
        else if (arr1[i]>arr2[j])
        {
            if (v.empty() || v.back() != arr2[j])
            v.push_back(arr2[j]);
            j++;
        }
        else if (v.empty() || v.back() != arr1[i])
        {
            v.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    
    while (i<n1)
    {
        if (v.empty() || v.back() != arr1[i])
        v.push_back(arr1[i]);
        i++;
    }
    
    while (j<n2)
    {
        if (v.empty() || v.back() != arr2[j])
        v.push_back(arr2[j]);
        j++;
    }
    return v;
}

void printallsubarray (vector <int> nums) {     /*VVVVV IMP*/
    int n = nums.size();

    for (int i = 0; i < n; i++)     //starting index
    {
        for (int j = i; j < n; j++)     //ending index
        {
            for (int k = i; k < j; k++)     //printing subarray
            {
                cout << nums[k] << " ";
            }
            cout << endl;
        }
    }
}

int Longest_SubArray_with_Sum_K (vector <int> arr, int k) {
    int n = arr.size();
    int left = 0, right = 0;
    long long sum = arr[0];
    int maxlength = 0;

    while (right < n)
    {
        while (left < right && sum > k) sum -= arr[left++];
        if (sum == k) maxlength = max(maxlength, right - left + 1);
        right++;
        if (right < n) sum += arr[right];
        return maxlength;
    }
}

/*IMPORTANT -> THIS WAS ASKED IN GOOGLE*/
int Longest_Consecutive_Sequence (vector<int> &arr) { 
    int n = arr.size();
    if (n == 0) return 0;
    int maxlength = 1;
    unordered_set <int> s;
    for (int i = 0; i < n; i++) {
        s.insert(arr[i]);
    }
    for(auto it : s) {
        if (s.find(it - 1) == s.end()) { /*s.end() simply points to the end of the set ie as same as not found position which is same as the one given by s.find() if it-1 is not found */
        int cnt = 1;
        int x = it;
        while (s.find(x + 1) != s.end()) {
            cnt++;
            x++;
        }
        maxlength = max(maxlength, cnt);
        }
    }
    return maxlength;
}




    void setZeroes(vector<vector<int>>& matrix) {
        //Instead of saving rows and columns we will now make it such that we see the first rows and first column of the matrix
        //First we will mark the first row and column
        int m = matrix.size();
        int n = matrix[0].size();
        int col0 = 1;


        //This deals with first row and col and makes them zero
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if (j != 0)
                    {
                        matrix[0][j] = 0;
                    } else {
                        int col1 = 0;
                    }
                }
            }
        }

        //Now we do not fuck up the first row and column cause we need it that is why we traverse from 1 to n/m
        //This take care of all the elements in the matrix except first row and col
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] != 0)
                {
                    if (matrix[0][j] == 0 || matrix[i][0] == 0)
                    {
                        matrix[i][j] = 0;
                    }
                }
                
            }
        }

        //Now matrix[0][0] is checked cause we did not check it in traversal and change the entire column if found 0
        if(matrix[0][0] == 0) for (int j = 0; j < m; j++) matrix[0][j] = 0;

        //Now col1 is checked cause we did not check it in traversal and change the entire row if found 0
        if(col0 == 0) for (int i = 0; i < m; i++) matrix[i][0] = 0;
    }


    void Transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    void spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0;
        int bottom = m-1;
        int left = 0;
        int right = n-1;

        while (top<=bottom && left<=right)
        {
        //left to right
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;

        //top to bottom
        for (int i = top; i < bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        //right to left
        if(top <= bottom) {
        for (int i = right; i >= left; i--)
        {
            ans.push_back(matrix[bottom][i]);
        }
        bottom--;
    }

    //bottom to top
    if(left<=right) {
        for (int i = bottom; i >= top; i--)
        {
            ans.push_back(matrix[i][left]);
        }
        left++;
    }
        }
    }

    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int cnt = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                for (int k = i; k <= j; k++)
                {
                    sum+=nums[k];
                }
                if(sum == k) cnt++;
                sum = 0;
            }
        }
    }



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for (int i = 0; i < n; i++)
        {
            if(i>0 && nums[i] == nums[i-1]) continue;
            int left = i+1, right = n-1;
            while (left < right)
            {
                int sum = nums[i]+nums[right]+nums[left];
                if(sum >0) left--;

                else if (sum < 0) right++;
                else {
                    ans.push_back({i,right,left});
                    left--;
                    right++;
                    while(left < right && nums[right] == nums[right-1]) right++;
                    while(left < right && nums[left] == nums[left+1]) left--;
                }
            }
        }
        return ans;
    }
};






int main() {
    
    return 0;
}