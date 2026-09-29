class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if ((m + n - 1) % 2 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(m + n, false)));

        dp[0][0][1] = true;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                for (int bal = 0; bal < m + n; bal++) {
                    if (!dp[row][col][bal])
                        continue;

                    if (row + 1 < m) {
                        int x = bal + (grid[row + 1][col] == '(' ? 1 : -1);

                        if (x >= 0)
                            dp[row + 1][col][x] = true;
                    }

                    if (col + 1 < n) {
                        int x = bal + (grid[row][col + 1] == '(' ? 1 : -1);

                        if (x >= 0)
                            dp[row][col + 1][x] = true;
                    }
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};