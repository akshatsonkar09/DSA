#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int helper(vector<int>& piles,int i,int j, vector<vector<int>> &dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int takefirst = piles[i] + min(helper(piles, i+2,j,dp), helper(piles, i+1, j-1,dp));
        int takelast = piles[j] + min(helper(piles, i+1,j-1,dp), helper(piles, i, j-2,dp));

        return dp[i][j] = max(takefirst, takelast);
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int> (n,-1));
        int alice = helper(piles, 0, n-1,dp);
        int bob = accumulate(piles.begin(), piles.end(),0) - alice;

        return alice > bob ? true : false;
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int> (n,-1));
        
        //dp initialization??
        dp[0][n-1] = 0; 

        int takefirst = 0;
        int takelast = 0;

        for (int i = 0; i<=n; i++)
        {
            for (int j =n-1; j>=i; j--)
            {
                takefirst = piles[i] + min(dp[i+2][j], dp[i-1][j-1]);
                takelast = piles[j] + min(dp[i-1][j+1], dp[i][j-2]);

                dp[i][j] = max(takefirst,takelast);
            }
        }

        dp[n-1][n-1] = max(takefirst, takelast);
        int bob = accumulate(piles.begin(), piles.end(),0) - dp[n-1][n-1];

        return dp[n-1][n-1] > bob ? true : false;
    }
};



class Solution {
private:
    int helper(int person, vector<int>&piles,int i, int m, int n, vector<vector<vector<int>>>& dp) {
        if(i >= n) return 0;
        if(dp[person][i][m] != -1) return dp[person][i][m];

        int stone = 0;
        int result = (person == 1) ? -1 : INT_MAX;

        for (int x = 1; x <= min(2*m,n-i); x++)
        {
            stone += piles[i+x-1];
            if(person ==1) {
                result  = max(result, stone + helper(0,piles,i+x,max(x,m),n, dp));
            } else {
                result = min(result, helper(1,piles,i+x, max(m,x),n, dp));
            }
        }
        return dp[person][i][m] = result;
    }

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(2,vector<vector<int>>(n+1,vector<int> (n+1,-1)));

        return helper(1,piles,0,1, n, dp);
    }
};



int main() {
    
    return 0;
}