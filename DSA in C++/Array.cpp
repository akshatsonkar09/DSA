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

int Longest_Subarray_with_sum_k(vector<int> &nums, int k) {
    // Hashmap method works with negative values as while while two pointer fails
    int n = nums.size();
    unordered_map <int , int> hashmap;
    // hashmap[0] = 0;
    hashmap[0] = -1;
    int presum = 0, maxlen = 0;
    for (int i = 0; i < n; i++)
    {
        presum += nums[i];
        
        if (hashmap.find(presum-k) != hashmap.end())
        {
            maxlen = max(maxlen, i-hashmap[presum-k]);
        }
        // hashmap[presum] = i;    //This is wrong because  want to store the first occurrence of each prefix sum because an earlier index gives a longer subarray.

        if(hashmap.find(presum-k) == hashmap.end()) {
            hashmap[presum] = i;
        }

    }
    return maxlen;
    }

int Longest_Subarray_With_sum_k(vector<int> &nums, int k) {
    int n = nums.size();
    int presum = 0, maxlen = 0;
    unordered_map<int,int> hashmap;

    for (int i = 0; i < n; i++)
    {
        presum += nums[i];

        if(presum == k) {
            // maxlen = i+1;
            maxlen = max(maxlen,i+1);       //above or below both are fine
        }

        int rem = presum-k;
        if(hashmap.find(rem) != hashmap.end()) {
            int len = i - hashmap[rem];      //why no +1 just take a small eg 1,2,4 with k = 6 and you will understand
            maxlen = max(maxlen, len);
        }
        
        if(hashmap.find(rem) == hashmap.end()) {
            hashmap[presum] = i;
    }
}
    return maxlen;
}


class NEXT_PERMUTATION {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int ind = -1;
        for (int i = n-2; i >= 0; i--)
        {
            if(nums[i] < nums[i+1]) {
                ind = i;
                break;
            }
        }

        if(ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n-1; i >= 0; i--) {
            if(nums[ind] < nums[i]) {
                swap(nums[ind],nums[i]);
                break;
            }
        }

        // reverse(nums.end(), nums.end()-n-ind-1); This is wrong 
        reverse(nums.end()-n-ind-1, nums.end());    //This is fine
        // reverse(nums.begin()+i+1, nums.end());      This is also correct

        return;
    }
};


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

        if (s.find(it-1) == s.end()) {      //start counting only if we are at first value of consecutive array
        
        int cnt = 1;
        int x = it;

        while (s.find(x+1) != s.end()) {
            cnt++;
            x++;
        }
        maxlength = max(maxlength, cnt);
        }
    }
    return maxlength;
}


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

    void setZeroes(vector<vector<int>>& matrix) {
        //Instead of saving rows and columns we will now make it such that we see the first rows and first column of the matrix and use them as labels
        
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


class LARGEST_SUBARRAY_WITH_SUM_0
{
private:
    /* data */
public:
    int Largest_Subarray_with_Sum_zero(vector<int> &A, int n) {
        unordered_map<int,int> mp;      //element and index 
        int sum= 0, maxi = 0;
        for (int i = 0; i < n; i++)
        {
            if(sum == 0) {
                maxi = i+1;
            }
            else {
                if(mp.find(sum) != mp.end()) {  //End and find same place par point nahi kar rahe hai yaani ki value mujhe mil gayi hai
                    maxi = max(maxi, i-mp[sum]);
                }
                else {
                    mp[sum] = i;
                }
            }
        }
        
    }
};


class COUNT_SUBARRAYS {
    private:

    public:
    int countSubarrays(vector<int>& A, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;            // Initialize with prefix XOR 0
        
        
        int prefixXor = 0;
        int count = 0;
        
        for (int num : A) {
            prefixXor ^= num;
            
            int target = prefixXor ^ k;
            
            // If target exists in map, add its frequency
            if (freq.find(target) != freq.end()) {
                count += freq[target];
            }
            // Store current prefix XOR in map
            freq[prefixXor]++;
        }
        return count;
    }
};


class COUNT_INVERSION_IN_ARRAY {
    private:
    
    int merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp;
        
        int left = low;
        int right = mid + 1;
        
        int cnt = 0;
        
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                cnt += (mid - left + 1); // All remaining left elements are inversions
                right++;
            }
        }
        
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
        
        // Copy back to original array
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
        return cnt;
    }
    
    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt = 0;
        
        if (low >= high) return cnt;
        
        int mid = (low + high) / 2;
        
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high);
        
        return cnt;
    }
    
    public:
    int numberOfInversions(vector<int>& a, int n) {
        return mergeSort(a, 0, n-1);
    }
};
    
    
class Solution {
public:
    int maxProductMethod1(vector<int>& nums) {
        int mini = nums[0];
        int maxi = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < 0) swap(mini,maxi);

            mini = min(nums[i], mini * nums[i]);
            maxi = max(nums[i], maxi * nums[i]);

            ans = max(ans, maxi);
        }
        return ans;    
    }

    int maxProductMethod2(vector<int>& nums) {
        int maxi = INT_MIN;
        int prod=1;

        for(int i=0;i<nums.size();i++)
        {
          prod*=nums[i];
          maxi=max(prod,maxi);
          if(prod==0)
           prod=1;
        }
        prod=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
          prod*=nums[i];

          maxi=max(prod,maxi);
          if(prod==0)
           prod=1;
        }
        return maxi;
    }
};


    

class REVERSE_PAIR {
private:
    int countPairs(vector<int>& nums, int low, int mid, int high) {
        int right = mid+1;
        int cnt = 0;
        for (int i = low; i <= mid; i++)
        {
            while (right <= high && nums[i] > 2*nums[right]) right++;
            cnt += (right-(mid+1));
        }
        return cnt;
    }

    void merge (vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid+1;

        while (left <= mid && right <= high)
        {
            if(nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }


            while (left<= mid)
            {
                temp.push_back(nums[left]);
                left++;
            }


            while (right <= high)
            {
                temp.push_back(nums[right]);
                right++;
            }

            for (int i = low; i <= high; i++) nums[i] = temp[i-low];
    }

    int mergesort(vector<int>& nums, int low, int high) {
        int cnt = 0;
        if(low >= high) return cnt;
        int mid = low + (high-low)/2;

        cnt += mergesort(nums, low, mid);
        cnt += mergesort(nums, mid+1, high);
        cnt += countPairs(nums,low,mid,high);
        merge(nums,low,mid,high);

        return cnt;
    }

public:
    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size()-1);
    }
};



int main() {
    
    return 0;
}