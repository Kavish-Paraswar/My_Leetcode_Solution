class Solution {
public:
    vector<vector<int>> ans;
    // vector<vector<int>> temp;

    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void dfs(int row, int col, int m, int n, vector<vector<int>>& vis,
             vector<vector<int>>& heights, int ocean) {

        if (vis[row][col] & ocean) {
            return;
        }

        vis[row][col] |= ocean;

        for (int i = 0; i < 4; i++) {
            int new_row = row + dir[i][0], new_col = col + dir[i][1];

            if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n &&
                !(vis[new_row][new_col] & ocean) &&
                heights[row][col] <= heights[new_row][new_col]) {

                dfs(new_row, new_col, m, n, vis, heights, ocean);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            dfs(i, 0, m, n, vis, heights, 1);
            dfs(i, n - 1, m, n, vis, heights, 2);
        }

        for (int i = 0; i < n; i++) {
            dfs(0, i, m, n, vis, heights, 1);
            dfs(m - 1, i, m, n, vis, heights, 2);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 3)
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};