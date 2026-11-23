
class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;
    int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    using T = tuple<int, int, int, int, int>;

    int dfs(vector<vector<int>>& grid) {
        stack<T> s;

        //  like r1, r2, c1 ,c2 , cur_pickup
        s.push({0, 0, 0, 0, grid[0][0]});
        int maxi = 0;

        while (!s.empty()) {
            auto [r1, c1, r2, c2, cur] = s.top();
            s.pop();

            if (cur < dp[r1][c1][r2])
                continue;

            if (r1 == n - 1 && c1 == n - 1) {
                maxi = max(maxi, cur);
                continue;
            }

            for (int i = 2; i < 4; i++) {
                for (int j = 2; j < 4; j++) {

                    int nr1 = r1 + dir[i][0];
                    int nc1 = c1 + dir[i][1];

                    int nr2 = r2 + dir[j][0];
                    int nc2 = c2 + dir[j][1];

                    if (nr1 >= n || nc1 >= n || nr2 >= n || nc2 >= n)
                        continue;

                    if (grid[nr1][nc1] == -1 || grid[nr2][nc2] == -1)
                        continue;

                    int plus = grid[nr1][nc1];

                    if (nr1 != nr2 || nc1 != nc2)
                        plus += grid[nr2][nc2];

                    int next = cur + plus;

                    if (next > dp[nr1][nc1][nr2]) {
                        dp[nr1][nc1][nr2] = next;
                        s.push({nr1, nc1, nr2, nc2, next});
                    }
                }
            }
        }
        return maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();

        dp.assign(n, vector<vector<int>>(n, vector<int>(n, -1)));

        return dfs(grid);
    }
};
