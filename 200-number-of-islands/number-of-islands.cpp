class Solution {
public:
    int m, n;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<char>>& grid, int row, int col) {

        stack<pair<int, int>> s;
        s.push({row, col});

        while (!s.empty()) {

            auto [cur_row, cur_col] = s.top();
            s.pop();

            for (int i = 0; i < 4; i++) {
                int next_row = cur_row + dir[i][0],
                    next_col = cur_col + dir[i][1];

                if (next_row >= 0 && next_row < m && next_col >= 0 &&
                    next_col < n && grid[next_row][next_col] == '1') {
                    grid[next_row][next_col] = '0';
                    dfs(grid, next_row, next_col);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();

        // vector<vector<bool>> vis(m, vector<bool>(n, false));
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    dfs(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};