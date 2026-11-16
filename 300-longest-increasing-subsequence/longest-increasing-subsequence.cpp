class Solution {
public:
    // int n;

    // int helper(int ind, int last_ind, vector<int>& nums, vector<int>& dp) {
    //     if (ind == n || last_ind == n)
    //         return 0;

    //     if (dp[last_ind + 1] != -1)
    //         return dp[last_ind + 1];

    //     int not_take = helper(ind + 1, last_ind, nums, dp), take = 0;

    //     if (last_ind == -1 || nums[last_ind] < nums[ind]) {
    //         take = 1 + helper(ind + 1, ind, nums, dp);
    //     }

    //     return dp[last_ind + 1] = max(take, not_take);
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;
        ans.push_back(nums[0]);

        for (int i = 0; i < n; i++) {
            int cur = nums[i];

            if (cur > ans.back()) {
                ans.push_back(cur);
            }

            else {
                int lower =
                    lower_bound(ans.begin(), ans.end(), cur) - ans.begin();

                ans[lower] = cur;
            }
        }

        return ans.size();
    }
};