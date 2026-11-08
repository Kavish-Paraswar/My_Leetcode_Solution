class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> col(n, 0), row(m, 0);
        set<pair<int, int>> s;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    col[j]++;
                    row[i]++;
                }
            }
        }
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && (row[i] > 1 || col[j] > 1)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};