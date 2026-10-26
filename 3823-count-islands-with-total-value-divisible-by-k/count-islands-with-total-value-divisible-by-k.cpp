class Solution {
public:
    int n, m, div;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool bfs(int i, int j, vector<vector<int>>& grid) {

        queue<pair<int, int>> q;
        q.push({i, j});

        long long sum = grid[i][j];
        grid[i][j] = 0;

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int next_row = row + dir[i][0], next_col = col + dir[i][1];

                if (next_row < m && next_row >= 0 && next_col >= 0 &&
                    next_col < n && grid[next_row][next_col] > 0) {
                    q.push({next_row, next_col});
                    sum += grid[next_row][next_col];
                    grid[next_row][next_col] = 0;
                }
            }
        }
        return sum % div == 0;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        div = k;
        m = grid.size(), n = grid[0].size();
        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    cnt += bfs(i, j, grid);
                }
            }
        }

        return cnt;
    }
};