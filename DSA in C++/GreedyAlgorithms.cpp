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

int main()
{

    return 0;
}