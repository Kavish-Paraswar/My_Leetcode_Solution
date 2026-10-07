class Solution {
public:
    int n;
    int helper(vector<int>& nums, int k, int ind, vector<int>& pref_sum,
               vector<vector<int>>& dp) {

        if (dp[ind][k] != -1)
            return dp[ind][k];

        if (k == 0) {
            if (ind == 0) {
                return pref_sum[n - 1];
            }
            return pref_sum[n - 1] - pref_sum[ind - 1];
        }

        int mini = 1e9;

        for (int i = ind; i < n - k; i++) {
            int cur_sum = pref_sum[i] - (ind > 0 ? pref_sum[ind - 1] : 0);
            int choose = helper(nums, k - 1, i + 1, pref_sum, dp);
            int temp = max(cur_sum, choose);

            mini = min(mini, temp);
        }

        return dp[ind][k] = mini;
    }
    int splitArray(vector<int>& nums, int k) {
        n = nums.size();

        vector<int> pref_sum(n);
        pref_sum[0] = nums[0];

        vector<vector<int>> dp(n, vector<int>(k, -1));

        for (int i = 1; i < n; i++)
            pref_sum[i] = pref_sum[i - 1] + nums[i];

        return helper(nums, k - 1, 0, pref_sum, dp);
    }
};