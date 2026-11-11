class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        if (n == 1)
            return grid[0][0];

        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        dp[0][0] = grid[0][0];

        // cost(max elevation) , row , col
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {
            auto [cost, row, col] = pq.top();
            pq.pop();

            for (int i = 0; i < 4; i++) {
                int next_row = row + dir[i][0], next_col = dir[i][1] + col;
                if (next_row >= 0 && next_row < n && next_col >= 0 &&
                    next_col < n) {

                    if (dp[next_row][next_col] != INT_MAX)
                        continue;

                    int cur_cost = max(cost, grid[next_row][next_col]);
                    if (dp[next_row][next_col] > cur_cost) {
                        pq.push({cur_cost, next_row, next_col});
                        dp[next_row][next_col] = cur_cost;
                    }
                }
            }
        }

        return dp[n - 1][n - 1];
    }
};