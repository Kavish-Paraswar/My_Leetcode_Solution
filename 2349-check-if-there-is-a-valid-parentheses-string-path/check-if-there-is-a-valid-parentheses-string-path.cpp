class Solution {
public:
    int m, n;

    bool dfs(vector<vector<char>>& grid, int i, int j, int bal,
             vector<vector<vector<int>>>& dp) {
        if (i >= m || j >= n)
            return false;

        if (grid[i][j] == '(')
            bal++;
        else
            bal--;

        if (bal < 0)
            return false;

        if (dp[i][j][bal] != -1)
            return dp[i][j][bal];

        if (i == m - 1 && j == n - 1)
            return dp[i][j][bal] = (bal == 0);

        bool down = dfs(grid, i + 1, j, bal, dp);
        bool right = dfs(grid, i, j + 1, bal, dp);

        return dp[i][j][bal] = (down || right);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(
            100, vector<vector<int>>(100, vector<int>(201, -1)));

        if ((m + n - 1) % 2 != 0)
            return false;

        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        return dfs(grid, 0, 0, 0, dp);
    }
};