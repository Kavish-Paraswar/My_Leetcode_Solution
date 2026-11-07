class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        queue<pair<int, int>> q;
        int ones = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    ones++;
            }
        }

        if (ones == 0)
            return 0;

        while (!q.empty()) {
            int sz = q.size();
            count++;

            for (int i = 0; i < sz; i++) {
                auto [row, col] = q.front();
                q.pop();

                for (int j = 0; j < 4; j++) {
                    int next_row = row + dir[j][0], next_col = dir[j][1] + col;

                    if (next_row >= 0 && next_row < m && next_col >= 0 &&
                        next_col < n && grid[next_row][next_col] == 1) {
                        grid[next_row][next_col] = 2;
                        q.push({next_row, next_col});
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    cout << i << " " << j;
                    return -1;
                }
            }
        }

        return count - 1;
    }
};