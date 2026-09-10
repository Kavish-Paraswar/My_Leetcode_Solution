class Solution {
public:
    int n, m;
    bool bfs(int i, int j, vector<vector<bool>>& vis,
             vector<vector<int>>& grid) {

        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        bool closed = true;

        while (!q.empty()) {
            auto [cur_row, cur_col] = q.front();
            q.pop();

            if (cur_row == 0 || cur_row == n - 1 || cur_col == 0 ||
                cur_col == m - 1) {
                closed = false;
            }

            for (int i = 0; i < 4; i++) {
                int temp_row = cur_row + dir[i][0],
                    temp_col = cur_col + dir[i][1];

                if (temp_row >= 0 && temp_row < n && temp_col >= 0 &&
                    temp_col < m && !vis[temp_row][temp_col] &&
                    grid[temp_row][temp_col] == 0) {
                    vis[temp_row][temp_col] = true;
                    q.push({temp_row, temp_col});
                }
            }
        }

        return closed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        int count = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 0)
                    if (bfs(i, j, vis, grid))
                        count++;
            }
        }

        return count;
    }
};