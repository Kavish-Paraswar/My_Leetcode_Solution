
class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges,
                vector<int>& passingFees) {

        int n = passingFees.size();

        vector<int> dp((maxTime + 1) * n, 1e9);

        dp[0] = passingFees[0];

        for (int t = 0; t <= maxTime; t++) {
            for (auto& e : edges) {
                int u = e[0], v = e[1], wt = e[2];

                if (t + wt <= maxTime) {

                    if (dp[t * n + u] != 1e9) {
                        dp[(t + wt) * n + v] =
                            min(dp[(t + wt) * n + v],
                                dp[t * n + u] + passingFees[v]);
                    }

                    if (dp[t * n + v] != 1e9) {
                        dp[(t + wt) * n + u] =
                            min(dp[(t + wt) * n + u],
                                dp[t * n + v] + passingFees[u]);
                    }
                }
            }
        }

        int ans = 1e9;

        for (int t = 0; t <= maxTime; t++) {
            ans = min(ans, dp[t * n + n - 1]);
        }

        return ans == 1e9 ? -1 : ans;
    }
};
