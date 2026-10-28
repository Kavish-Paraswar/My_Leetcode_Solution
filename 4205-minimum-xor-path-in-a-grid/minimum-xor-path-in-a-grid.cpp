class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<unordered_set<int>>> dp(m, vector<unordered_set<int>>(n));

        dp[0][0].insert(grid[0][0]);

        int dir[2][2] = {{-1, 0}, {0, -1}};

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (row == 0 && col == 0)
                    continue;

                for (int i = 0; i < 2; i++) {
                    int nr = row + dir[i][0];
                    int nc = col + dir[i][1];

                    if (nr >= 0 && nc >= 0) {
                        for (int val : dp[nr][nc]) {
                            dp[row][col].insert(val ^ grid[row][col]);
                        }
                    }
                }
            }
        }

        int ans = INT_MAX;

        for (int val : dp[m - 1][n - 1])
            ans = min(ans, val);

        return ans;
    }
};