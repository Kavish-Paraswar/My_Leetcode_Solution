class Solution {
public:
    int n, m;

    bool bfs(int i, int j, vector<vector<int>>& grid,
             vector<vector<bool>>& vis) {
        bool flag = true;

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty()) {
            auto [cur_row, cur_col] = q.front();
            grid[cur_row][cur_col] = 1;
            q.pop();

            if (cur_row == 0 || cur_row == n - 1 || cur_col == 0 ||
                cur_col == m - 1) {
                flag = false;
            }
            for (int i = 0; i < 4; i++) {
                int next_row = cur_row + dir[i].first,
                    next_col = cur_col + dir[i].second;

                if (next_row >= 0 && next_row < n && next_col < m &&
                    next_col >= 0 && !vis[next_row][next_col] &&
                    grid[next_row][next_col] == 0) {
                    q.push({next_row, next_col});
                    vis[next_row][next_col] = true;
                }
            }
        }

        return flag;
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int cnt = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    vis[i][j] = true;
                    cnt += bfs(i, j, grid, vis);
                }
            }
        }

        return cnt;
    }
};