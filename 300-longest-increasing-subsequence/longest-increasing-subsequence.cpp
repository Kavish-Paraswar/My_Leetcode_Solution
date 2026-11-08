class Solution {
public:
    int n;

    int helper(int ind, int last_ind, vector<int>& nums,
               vector<vector<int>>& dp) {
        if (ind == n || last_ind == n)
            return 0;

        if (dp[ind][last_ind + 1] != -1)
            return dp[ind][last_ind + 1];

        int not_take = helper(ind + 1, last_ind, nums, dp), take = 0;

        if (last_ind == -1 || nums[last_ind] < nums[ind]) {
            take = 1 + helper(ind + 1, ind, nums, dp);
        }

        return dp[ind][last_ind + 1] = max(take, not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        // for (int i = 0; i < n; i++) {
        //     dp[i][0] = 1;
        //     dp[0][i] = 1;
        // }

        return helper(0, -1, nums, dp);
    }
};