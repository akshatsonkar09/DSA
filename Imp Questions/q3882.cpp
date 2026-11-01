#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    void func(vector<vector<int>> &grid, vector<vector<vector<bool>>> &dp, int r, int c, int currxor, int &ans)
    {
        if (r < 0 || c < 0)
            return;

        currxor = currxor ^ grid[r][c];
        // That is insufficient because reaching the same cell through different paths can produce different XOR values.

        if (dp[r][c][currxor])
            return;

        dp[r][c][currxor] = true;
        // This means that exact state has already been visited

        if (r == 0 && c == 0)
        {
            ans = min(ans, currxor);
            return;
        }

        func(grid, dp, r, c - 1, currxor, ans);
        func(grid, dp, r - 1, c, currxor, ans);
        return;
    }

public:
    int minCost(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = INT_MAX;
        // For XOR if min is needed then undesirable can be made INT_MAX and vice versa??
        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(1024, false)));
        func(grid, dp, m - 1, n - 1, 0, ans);
        return ans;
    }
};

int main()
{
    return 0;
}