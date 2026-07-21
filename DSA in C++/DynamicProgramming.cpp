#include <iostream>
#include <bits/stdc++.h>

using namespace std;


/*
Think of memoization as
"I don't know this answer.
Let me ask recursion."

Think of tabulation as
"I already computed this answer earlier.
Let me read it from the table."
*/

class CLIMBINGSTAIRS
{
private:
    void func_mine_recursion(int n, int &cnt)
    {
        if (n == 0)
        {
            cnt++;
            return;
        }
        if (n < 0)
            return;

        func_mine_recursion(n - 1, cnt);
        func_mine_recursion(n - 2, cnt);
    }

    int func_recursion_refined(int n)
    {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;

        return func_recursion_refined(n - 1) + func_recursion_refined(n - 2);
    }

    int func_dp(int n, vector<int> &dp)
    {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];

        return dp[n] = func_dp(n - 1, dp) + func_dp(n - 2, dp);
        // dp[n] = func_dp(n-1,dp) + func_dp(n-2, dp);
        // return dp[n];
    }

public:
    int climbStairs_mine_recursion(int n)
    {
        int cnt = 0;
        func_mine_recursion(n, cnt);
        return cnt;
    }

    int climbstairs_recursion_refined(int n)
    {
        return func_recursion_refined(n);
    }

    int climbstairs_dp_memorization(int n)
    {
        vector<int> dp(n + 1, -1);
        func_dp(n, dp);
        return dp[n];
        // return  func_dp(n, dp);
    }

    int climbstairs_dp_tabulation(int n)
    {
        vector<int> dp(n + 1, -1);
        // base cases because we need it to calc dp for first iteration
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2 /*because we do i-2*/; i < n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }

    int climbstair_dp_tabulation_spaceoptimized(int n)
    {
        if (n <= 1)
            return 1;

        int prev2 = 1; // dp[0]
        int prev1 = 1; // dp[1]

        // j = i-2
        for (int i = 2; i <= n; i++)
        {
            // 1st iteration-> dp[i] = dp[i-1] + dp[i-2]
            //                 dp[j+2] = dp[j+1] + dp[j]
            // 2nd iteration-> dp[j+3] = dp[j+2] + dp[j+1]
            //    diagonal relation of prev1 & prev2 and curr & prev1
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

class FROGJUMPINGNSTAIRS
{
private:
public:
    int frog_jump_recursion(int n, vector<int> &height)
    {
        if (n == 0)
            return 0;
        int left = frog_jump_recursion(n - 1, height) + abs(height[n] - height[n - 1]);

        int right = INT_MAX;
        if (n > 1)
        {
            right = frog_jump_recursion(n - 2, height) + abs(height[n] - height[n - 2]);
        }

        return min(left, right);
    }

    int from_jump_dp_space_optimized(int n, vector<int> &height)
    {
        int prev1 = 0; // dp[0]
        int prev2 = 0; // dp[-1] not used initially

        for (int i = 1; i < n; i++)
        {
            int fs = prev1 + abs(height[i] - height[i - 1]);
            int ss = INT_MAX;
            if (i > 1)
                ss = prev2 + abs(height[i] - height[i - 2]);
            int curr = min(fs, ss);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

class Solution
{
public:
    int rob(vector<int> &nums)
    {
    }
};

class HOUSEROBBER
{
private:
public:
    int rob_tabulation_dp(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        int maxi = INT_MIN;
        for (int i = 1; i < nums.size(); i++)
        {
            int pick = nums[i];
            if (i > 1)
                pick += dp[i - 2];
            int notpick = dp[i - 1];
            dp[i] = max(pick, notpick);
        }
        return dp[n - 1];
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        vector<int> dp(n, -1);
        int prev2 = nums[0];               // dp[0] = nums[0]; aka i-2
        int prev1 = max(nums[0], nums[1]); // dp[1] = max(dp[1], dp[0]); aka i-1 which is not needed for first iteration
        int curr = 0;
        for (int i = 2; i < nums.size(); i++)
        {
            curr = max(nums[i] + prev2, prev1);
            prev2 = prev1; // i-2 hojayega i-1
            prev1 = curr;  // i-1 hojayega i
        }
        return prev1;
    }
};

//N*3 means 3 columns and n rows


// 2D DYNAMIC PROGRAMMING
// dp[index][state] where state could be: ,previous activity, previous color, previous choice etc.


class NINJA_TRAINING    //Three activities which give some experience only one activity can be performed at that day. So maximize experience
{
private:
    int helper(int day, int lasttask, vector<vector<int>> &points, vector<vector<int>> &dp);
// Suppose today is day i and yesterday's activity was last. You try every activity except last.

    int helpermemoirization(int day, int lasttask, vector<vector<int>> &points, vector<vector<int>> &dp) {
        //this is base case so we are just taking the maximum possible
        if(day == 0) {
            int maxi = 0;
            for (int task = 0; task < 3; task++)
            {
                if(task != lasttask) maxi = max(maxi, points[0][task]);
            }
            return maxi;
        }

        //If value is already in the dp
        if (dp[day][lasttask] != -1)
            return dp[day][lasttask];

        int ans = 0;

        for (int task = 0; task < 3; task++)
        {
            if(task != lasttask) {
                ans = max(ans, points[day][task] + helper(day-1, task, points, dp));
            }
        }
        
        /*  This is how ans = max(...) works
        i) n-1th day activity i done   n-2th day with activity i as lasttask
        1)            30             +                f(1,0) and so on
        2)            60             +                f(1,1) and so on
        3)            90             +                f(1,2) and so on
        */
       return dp[day][lasttask] = ans;
    }



public:

    int ninjaTraining(int n, vector<vector<int>> &points) {
       vector<vector<int>> dp(n, vector<int>(4, -1));   //no previous activity is 3 that is why a vector of size 4 even with 3 activities

        // Start the recursive calculation from the last day with no previous activity
        return helper(n-1, 3, points, dp);
    }

    int ninjaTraining_Tabulation(int n, vector<vector<int>> &points) {
        vector<vector<int>> dp(n, vector<int>(4, -1));

        //Based on if last task 1 than today task is either 0 or 2
        //Base Case
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][2], points[0][3]);
        dp[0][2] = max(points[0][1], points[0][3]);
        dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

        for (int day = 0; day < n; day++)
        {
            for (int lasttask = 0; lasttask < 4; lasttask++)
            {
                dp[day][lasttask] = 0;      //Just just to make it zero before computing real value and help against negative values that is why no -1
                
                for (int task = 0; task < 3; task++)
                {
                    if(task != lasttask) {
                        int point = points[day][task] + dp[day-1][task];
                        dp[day][lasttask] = max(dp[day][lasttask], point);
                    }
                }
            }
        }
        return dp[n-1][3];
        
    }
};


class GRID_2D_DP {
private:
    int func_recursion(int i, int j) {
        if(i == 0 && j == 0) return 1;
        if( i<0 || j<0) return 0;
        
        int up = func_recursion(i-1,j);
        int left = func_recursion(i,j-1);
        return up+left;
        //We are going from m-1 and n-1 to 0 is cause this way we do not need to take care of m,n every time
    }
    
    int func_memoization(int i, int j, vector<vector<int>> &dp) {
        if(i ==0 && j == 0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = func_memoization(i-1,j,dp);
        int left = func_memoization(i,j-1,dp);
        return dp[i][j] = up+left;
    }
    int func_tabulation(int m, int n) {
        //Tabulation is bottom up because we go from bottom to up in recursion tree
        vector<vector<int>> dp(m,vector<int>(n,-1));
        //declare the base case
        dp[0][0] = 1;
        
        //Express all states in for loop
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(i==0 && j==0) continue;

                int up =0, left = 0;
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
        return dp[m-1][n-1];
    }

public:
    int uniquePaths(int m, int n) {
        return func_tabulation(m,n);
    }
};


int main()
{

    return 0;
}