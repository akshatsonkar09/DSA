#include <iostream>
#include <bits/stdc++.h>

using namespace std;

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

int main()
{

    return 0;
}