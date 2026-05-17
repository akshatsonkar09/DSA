vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> ans = {0};

        for (int j = 0; j < matrix[0].size(); j++) {
            for (int i = 0; i < matrix.size(); i++) {
                ans[j] += matrix[i][j];
            }
        }
        return ans;
    }