#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
class meetingslot
{
public:
    int starttime;
    int endtime;
    int position;

    meetingslot(int st, int et, int ps)
    {
        starttime = st;
        endtime = et;
        position = ps;
    }
};

int N_Meetings_in_one_room(int start[], int end[], int N)
{
    vector<meetingslot> arr;

    for (int i = 0; i < N; i++)
    {
        arr[i].starttime = start[i];
        arr[i].endtime = end[i];
        arr[i].position = i;
        this is for array but for vector we should use emplace back
    }
}
*/
// This much is fine but you can actually improve it based by playing it smartly

// Below is more efficient written code

class meetingslot
{
public:
    int starttime, endtime, position;
    meetingslot(int st, int et, int ps) : starttime(st), endtime(et), position(ps) {}
};

int N_Meetings_in_one_room(int start[], int end[], int N)
{
    if (N == 0) return 0;
    
    vector<meetingslot> arr;

    for (int i = 0; i < N; i++)
    {
        arr.emplace_back(start[i], end[i], i);
    }

    sort(arr.begin(), arr.end(), [](meetingslot a, meetingslot b)
         { return a.endtime < b.endtime; });

    int cnt = 1;
    int freetime = arr[0].endtime;
    vector<int> pos;
    pos.push_back(arr[0].position);

    for (int i = 1; i < N; i++) // starting from 1 cause we have to check from 1st index as 0th index is default case
    {
        if (arr[i].starttime > freetime)
        {
            cnt++;
            freetime = arr[i].endtime;
            pos.emplace_back(arr[i].position);
        }
    }
    return cnt;
    //some may ask you to return position array;
}

double Fractional_Knapsack (vector<pair<int,int>> nums, int weight) {
    //vector -> [(100,20), (60,10), (100,50), (200,50)]


    sort(nums.begin(), nums.end(), [](const pair<int,int> &a, const pair<int,int> &b) {
        return (double)a.first / a.second > (double)b.first / b.second;
    });

    double totalval = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i].second <= weight) {
            totalval += nums[i].first;
            weight -= nums[i].second;
        } else {
            totalval += (((double)nums[i].first/(double)nums[i].second)*weight);
            break;
        }
    }
    return totalval;
}


class INSERT_INTERVALS {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int i = 0;

        // Problem with this was that you could not figure out how to push overlapping into ans so while is used and pushing into vector was manual
        // for (int i = 0; i < intervals.size(); i++)
        // {
        //     //left part no overlapping
        //     if(intervals[i][1] < newInterval[0]) ans.push_back(intervals[i]);
        
        //     //right part no overlapping
        //     else if(intervals[i][0] > newInterval[1]) ans.push_back(intervals[i]);
        
        //     //overlapping part
        //     else {
            //         smallest = min(smallest,intervals[i][0], newInterval[0]);
            //         largest = max(largest,intervals[i][1], newInterval[1]);
            //     }
            // }
            
            
            
        //left part no overlapping
        while (i<n && intervals[i][1] < newInterval[0])
        {
            ans.push_back(intervals[i]);
            i++;
        }


        //overlapping part
        while(i<n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(intervals[i][0], newInterval[0]);
        newInterval[1] = max(intervals[i][1], newInterval[1]);
        i++;
        }
        ans.push_back(newInterval);


        //right poverlapping part
        // while (i<n && intervals[i][0] > newInterval[1]) this part is wrong
        while(i<n)
        {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};



class MERGE_INTERVALS {
    private:
        void solve(vector<vector<int>>& intervals, vector<vector<int>> &ans, int &i) {
            int smallest = intervals[i][0], largest = intervals[i][1];

            while (i+1< intervals.size() && intervals[i+1][0] <= largest) 
            {
                largest = max(largest,intervals[i+1][1]);
                i++;
            }

            ans.push_back({smallest,largest});
            i++;

            return;
        }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int i = 0;

        while(i<n) {
                solve(intervals,ans,i);
            }

            return ans;
    }
};



int main()
{

    return 0;
}