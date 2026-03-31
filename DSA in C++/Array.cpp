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

void printallsubarray (vector <int> nums) {
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


int main() {
    
    return 0;
}