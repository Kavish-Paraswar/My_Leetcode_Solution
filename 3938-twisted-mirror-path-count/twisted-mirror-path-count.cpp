class Solution {
public:
    int mod = 1e9 + 7, n, m;

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(3, 0)));

        vector<vector<int>> vis(m, vector<int>(n, 0));

        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = 1;

        dp[0][0][0] = 1;

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int dir = 0; dir <= 2; dir++) {
                int ways = dp[row][col][dir];

                if (ways == 0) {
                    continue;
                }

                if (row == m - 1 && col == n - 1) {
                    continue;
                }

                for (int d = 1; d <= 2; d++) {
                    if (grid[row][col] == 1) {
                        if (dir == 0 || d != (dir == 1 ? 2 : 1)) {
                            continue;
                        }
                    }

                    int nr = row + (d == 2);
                    int nc = col + (d == 1);

                    if (nr >= m || nc >= n) {
                        continue;
                    }

                    dp[nr][nc][d] =
                        (dp[nr][nc][d] + ways) % mod;

                    if (!vis[nr][nc]) {
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }

        int ans = 0;

        for (int d = 0; d <= 2; d++) {
            ans = (ans + dp[m - 1][n - 1][d]) % mod;
        }

        return ans;
    }
};