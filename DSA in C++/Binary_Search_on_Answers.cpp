#include <iostream>
#include <bits/stdc++.h>


/*
VVV IMP trick in vs code
Binary Search Polarity

1. False → True (FFFFTTTT)
   - Condition becomes easier as mid increases.
   - Answer = First True (minimum valid value).

   if(check(mid)){
       ans = mid;
       high = mid - 1;
   }
   else low = mid + 1;


2. True → False (TTTTFFFF)
   - Condition becomes harder as mid increases.
   - Answer = Last True (maximum valid value).

   if(check(mid)){
       ans = mid;
       low = mid + 1;
   }
   else high = mid - 1;


Trick:
Ask: "As mid increases, does the condition become easier or harder?"
Easier  → FFFFTTTT
Harder  → TTTTFFFF

For cond 1-> low is answer
For cond 2-> high is answer
*/


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
    int totalsum (vector<int>& weights) {
        int sum = 0;
        for (auto it: weights)
        {
           sum += it;
        }
        return sum;
    }

        int maxweight(vector<int>& weights) {
        int mx = 0;
        for (int x : weights)
            mx = max(mx, x);
        return mx;
    }


bool minweight(vector<int>& weights, int days, int cap) {
        int usedDays = 1;
        int load = 0;

        for (int w : weights) {
            if (load + w <= cap) {
                load += w;
            } else {
                usedDays++;
                load = w;
            }
        }

        return usedDays <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = maxweight(weights), high = totalsum(weights);

        while (low <= high)
        {
            int mid = low + (high-low)/2;
            bool possible = minweight(weights, days, mid);
            if(possible) high = mid-1;
            else low = mid+1;
        }
        
    }
};

//Maximum possible minimum distance between two cows
//If n cows can be placed in m stalls at coordinates of nums[m].
class AGGRESSIVECOWS {
    private:
        bool canPlace(vector<int>& stalls, int cows, int min_dist) {
            int countcows = 1, lastcow = stalls[0];
            for (int i = 1; i < stalls.size(); i++)
            {
                if(stalls[i] - lastcow >= min_dist) {
                    countcows++;
                    lastcow = stalls[i];
                }
                if(countcows>=cows) return true;
            }
            return false;
        }
    public:
        int aggressiveCows(vector<int>& stalls, int cows) {
            int n = stalls.size();
            sort(stalls.begin(), stalls.end());
            int low = 0, high = stalls.back() - stalls.front(); //or a[n-1]-a[0]
            int ans = 0;

            while (low <= high)
            {
                int mid = low + (high-low)/2;
                if(canPlace(stalls,cows, mid)) {
                    ans = mid;
                    low = mid+1;
                }
                else high = mid-1;
            }
            return high;    //return ans;
        }
};


class ALLOCATEBOOKS
//An array named book which has books i with pages book[i] 
//Divide among s no. of students such that max of pages allocated to a student is min
//In simple language such that work is distributed as equally as possible
{
private:
    int findsum(vector<int> &arr) {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
        }
        return sum;
    }
        
    bool ispossible(vector<int>& arr, int students, int pages) {
        int stud = 1;
        int sum=0;    //sir took long long
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if(sum>pages) {
                stud++;
                sum=arr[i];// sum=0;
            }

            /*
            or more cleanly:
            if(sum + arr[i] <= pages) sum += arr[i];
            else {
                stud++;
                sum = arr[i];
            }
            */

            if(stud > students) return false;
        }
        return true;
    }
public:
    int findPages(vector<int>& arr, int students) {
        if(students > arr.size()) return -1;

        //assuming arr to be sorted
        int low = *max_element(arr.begin(),arr.end());// int low=arr[0];
        int high=findsum(arr);
        int ans = arr[0];
        while (low<=high) 
        {
            int mid = low + (high-low)/2;
            if(ispossible(arr,students,mid)) {
                ans = mid;
                high = mid-1;  //pages kam karne hai so high dec this is min possible pages as our mid is in search space of pages
            }
            else low= mid+1;
        }
        return low;     //return high;   //Polarity FFFTTTT
    }
};

class Minimise_Maximum_Distance_between_Gas_Stations
{
private:
    
public:
    long double minimiseMaxDistance(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> howmany (n,0);

        for (int i = 1; i <= k; i++)        //This is for finding where to put each gasstation
        {
            long double max_value = -1;
            int max_value_index = -1;

            for (int i = 0; i < n-1; i++)   //This loop is for finding the maximum section length in the array and incrementing how many when we place a station in that section length
            {
                long double diff = arr[i+1]-arr[i];
                long double section_length = diff/(howmany[i]+1);
                if(max_value<section_length) {
                    max_value = section_length;
                    max_value_index = i;
                }
            }
            howmany[max_value_index]++;
        }
        
        long double maxAns = -1;
        for (int i = 0; i < n-1; i++)
        {
            long double diff = arr[i+1]-arr[i];
            long double section_length = diff/(howmany[i]+1);
            maxAns = max(maxAns, section_length);
        }
    }

    long double minimiseMaxDistancePriorityQueue(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> howmany (n-1,0);
        priority_queue<pair<long double, int>> pq;

        for (int i = 0; i < n-1; i++) pq.push({arr[i+1]-arr[i],i}); //pushing values into queue

        for (int gasStation = 1; gasStation <= k; gasStation++)
        {
            auto val = pq.top();
            pq.pop();

            int maxval = val.first;
            int index = val.second;
            howmany[index]++;

            long double diff = arr[index+1]-arr[index];
            long double sequence_length = diff/(howmany[index]+1);
            pq.push({sequence_length,index});
        }
        return pq.top().first;
    }
};


class MEDIAN_OF_2_SORTED_ARRAY {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);

        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = 0, high = n1;

        while (low <= high)
        {
            //Setting Partitions
            int cut1 = low + (high-low)/2;
            int cut2 = (n1+n2+1)/2 - cut1;  //question -> cant I just do n2 - cut1


            //Setting up partitions edge values as number or int max-min if no value present
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];

            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];

            //Checking condition for correct partition
            // This if statement part is weak 
            if(left1 <= right2 && left2 <= right1) {
                if((n1+n2)%2 == 0)
                return ((max(left1,left2)+min(right1, right2))/2.0);  //if even just add and return divide by 2 because we have two values
                else return max(left1, left2);
            }

            else if(left1 > right2) {
                high= cut1-1;
            }
            else low = cut1+1;
            }
            return 0.0;
    }
};


class Kth_ELEMENT_OF_TWO_SORTED_ARRAY {
public:
        int kthElement (vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums2.size() < nums1.size()) return kthElement(nums2, nums1,k);

        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = max(k-n2,0), high = min(k,n1);
        int left = k;

        while (low <= high)
        {
            //Setting Partitions
            int cut1 = low + (high-low)/2;
            int cut2 = k - cut1; 

            //Setting up partitions edge values as number or int max-min if no value present
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];

            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];

            //Checking condition for correct partition
            // This if statement part is weak 
            if(left1 <= right2 && left2 <= right1) {
                return max(left1, left2);
            }

            else if(left1 > right2) {
                high= cut1-1;
            }
            else low = cut1+1;
            }
            return 0.0;
    }
};




int main() {
    
    return 0;
}