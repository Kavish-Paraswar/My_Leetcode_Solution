class Solution {
public:
    int n;

    int helper(int ind, int last_ind, vector<int>& nums, vector<int>& dp) {
        if (ind == n || last_ind == n)
            return 0;

        if (dp[last_ind + 1] != -1)
            return dp[last_ind + 1];

        int not_take = helper(ind + 1, last_ind, nums, dp), take = 0;

        if (last_ind == -1 || nums[last_ind] < nums[ind]) {
            take = 1 + helper(ind + 1, ind, nums, dp);
        }

        return dp[last_ind + 1] = max(take, not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();

        vector<int> dp(n + 1, 0);

        // for (int i = 0; i < n; i++) {
        //     dp[i][0] = 1;
        //     dp[0][i] = 1;
        // }

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int last_ind = -1; last_ind < ind; last_ind++) {
                int not_take = dp[last_ind + 1], take = 0;

                if (last_ind == -1 || nums[last_ind] < nums[ind]) {
                    take = 1 + dp[ind + 1];
                }

                dp[last_ind + 1] = max(take, not_take);
            }
        }

        return dp[0];
    }
};