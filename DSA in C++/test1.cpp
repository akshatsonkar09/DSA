#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> matrix (m,vector<int>(n,-1));

        int r = k%(m*n);
        if(r == 0) return grid;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int index = i*n+j;
                int newIndex = (index+k)%(m*n);
                int row = newIndex/n;
                int col = newIndex%n;
                
                matrix[i][j] = grid[row][col];
            }
        }
        return matrix;
    }
};

int main()
{
    return 0;
}