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

class Solution {
private:
    pair<int, int> findmaxandmin (vector<int>& bloomDay) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for (auto it: bloomDay)
        {
           maxi = max(maxi,it);
           mini = min(mini,it);
        }
        return {maxi,mini};
    }

    int maxbouquet(vector<int>& bloomDay, int k, int day) {
        int seqcnt = 0;
        int cnt = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if(bloomDay[i] <= day) cnt++;
            else {
                seqcnt += cnt/k;
                cnt = 0;
            }
        }
        return seqcnt;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < m*k) return -1;
        pair<int,int> temp = findmaxandmin(bloomDay);
        int low = temp.second, high = temp.first;
        int ans = -1;
        while (low<=high)
        {
            int mid = low + (high-low)/2;
            int m_dash = maxbouquet(bloomDay,k, mid);
            if(m_dash >= m) {high = mid-1;
            ans = mid;
        }
            else low = mid +1;
        }
        return ans;
    }
};
int main() {
    
    return 0;
}