#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int Lower_Bound(vector<int> &arr, int n, int val)
{
    // int n = arr.size();
    int low = 0, high = n - 1;
    int mid;
    int ans = n;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] >= val) // Difference between lower and upper is just changing to arr[mid] > val
        {
            high = mid - 1;
            ans = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int rowwithMax1s(vector<vector<int>> &matrix, int row, int col)
{
    int count_max = 0;
    int index = -1;
    // n x log2 m Time complexity
    for (int i = 0; i < row; i++)
    {
        int count_ones = col - Lower_Bound(matrix[i], col, 1);
        if (count_ones > count_max)
        {
            count_max = count_ones;
            index = i;
        }
    }
    return index;
}

int Search_in_2D_Matrix(vector<vector<int>> &mat, int n, int m, int target)
{
    int low = 0, high = (n * m) - 1, mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        int row = mid / m, col = mid % m; // row ke liye divide aur col ke liye modulus aur humesha number of columns se divide hote hai

        if (mat[row][col] == target)
            return true;
        else if (mat[row][col] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

pair<int, int> Search_in_2D_Matrix_II(vector<vector<int>> &mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();
    int row = 0, col = m - 1; // starting points can be (m,0) or (0,m)

    while (row < n && col >= 0) // I wrote != instead of <>
    {
        if (mat[row][col] == target)
            return {row, col};
        else if (mat[row][col] < target)
            row++;
        else
            col--;
    }
    return {-1, -1};
}

int main()
{
    vector<vector<int>> matrix = {{0, 0, 1, 1, 1},
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 1, 1},
                                  {0, 1, 1, 1, 1}};
    // n is mostly row while m is mostly column

    cout << "Row with MAx 1s: " << rowwithMax1s(matrix, 3, 4) << endl;

    matrix = {{3, 4, 7, 9},
              {12, 13, 16, 18},
              {20, 21, 23, 24}};

    cout << "Search in 2D for value 16: " << Search_in_2D_Matrix(matrix, 4, 5, 16) << endl;
    // Instead of passing row and columns you can use row = matrix.size() and col = matrix[0].size()

    matrix = {{1, 4, 7, 11, 15},
              {2, 5, 8, 12, 19},
              {3, 6, 9, 16, 22},
              {10, 13, 14, 17, 24}};
    // Here rows and columns both are sorted

    // cout << "Search in a sorted row and sorted column matrix: " << Search_in_2D_Matrix_II(matrix, 14) << endl; Cannot print pair using cout
    auto ans = Search_in_2D_Matrix_II(matrix, 18);
    cout << "Search in a sorted row and sorted column matrix: " << ans.first << " " << ans.second << endl;

    return 0;
}