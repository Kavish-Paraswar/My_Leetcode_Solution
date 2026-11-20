class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        unordered_map<int, vector<int>> dp;
        int ans = 0;

        for (int x : nums) {
            if (dp.find(x - 1) == dp.end())
                dp[x - 1] = {0, 0};

            if (dp.find(x) == dp.end())
                dp[x] = {0, 0};

            if (dp.find(x + 1) == dp.end())
                dp[x + 1] = {0, 0};
            int a = dp[x - 1][0], b = dp[x - 1][1], c = dp[x][0], d = dp[x][1];

            int org = max({1, a + 1, b + 1}), inc = max({1, c + 1, d + 1});

            dp[x][0] = max(dp[x][0], org);
            dp[x + 1][1] = max(dp[x + 1][1], inc);

            ans = max({ans, dp[x][0], dp[x + 1][1]});
        }

        return ans;
    }
};