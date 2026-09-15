class Solution {
public:
    int n;

    bool helper(int cur, int k, vector<int>& stones, set<int>& s,
                vector<vector<bool>>& vis, vector<vector<bool>>& dp) {
        if (cur == stones[n - 1])
            return true;

        int i = lower_bound(stones.begin(), stones.end(), cur) - stones.begin();

        if (vis[i][k])
            return dp[i][k];

        vis[i][k] = true;

        int op1 = cur + k;
        int op2 = cur + k - 1;
        int op3 = cur + k + 1;

        bool a = false, b = false, c = false;

        if (s.find(op1) != s.end())
            a = helper(op1, k, stones, s, vis, dp);

        if (k - 1 > 0 && s.find(op2) != s.end())
            b = helper(op2, k - 1, stones, s, vis, dp);

        if (s.find(op3) != s.end())
            c = helper(op3, k + 1, stones, s, vis, dp);

        dp[i][k] = a || b || c;

        return dp[i][k];
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();

        if (n > 1 && stones[1] != 1)
            return false;

        set<int> s(stones.begin(), stones.end());

        vector<vector<bool>> vis(n, vector<bool>(n + 1, false));
        vector<vector<bool>> dp(n, vector<bool>(n + 1, false));

        return helper(1, 1, stones, s, vis, dp);
    }
};