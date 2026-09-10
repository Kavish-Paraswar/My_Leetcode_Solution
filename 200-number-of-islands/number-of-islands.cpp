class Solution {
public:
    int n, m;
    void bfs(int i, int j, vector<vector<char>>& grid,
             vector<vector<bool>>& vis) {
        // if (i >= n || j >= m)
        //     return;

        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;
        vector<vector<int>> dir = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

        while (!q.empty()) {
            // int sz = q.size();
            auto [cur_i, cur_j] = q.front();
            q.pop();
            vis[cur_i][cur_j] = true;

            for (int i = 0; i < 4; i++) {
                int temp_i = cur_i + dir[i][0], temp_j = cur_j + dir[i][1];

                if (temp_i >= 0 && temp_i < n && temp_j >= 0 && temp_j < m &&
                    grid[temp_i][temp_j] == '1' && !vis[temp_i][temp_j]) {
                    vis[temp_i][temp_j] = true;
                    q.push({temp_i, temp_j});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        int count = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    count++;
                    bfs(i, j, grid, vis);
                }
            }
        }

        return count;
    }
};