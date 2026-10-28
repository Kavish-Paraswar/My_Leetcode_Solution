class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(1024, false)));

        dp[0][0][grid[0][0]] = true;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (row == 0 && col == 0)
                    continue;

                for (int val = 0; val < 1024; val++) {
                    if (row > 0 && dp[row - 1][col][val])
                        dp[row][col][val ^ grid[row][col]] = true;

                    if (col > 0 && dp[row][col - 1][val])
                        dp[row][col][val ^ grid[row][col]] = true;
                }
            }
        }

        for (int i = 0; i < 1024; i++) {
            if (dp[m - 1][n - 1][i])
                return i;
        }

        return -1;
    }
};