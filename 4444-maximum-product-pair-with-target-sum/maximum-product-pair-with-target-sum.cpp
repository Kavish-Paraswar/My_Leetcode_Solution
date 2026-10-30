class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans(2, -1);
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (nums[i] + nums[j] == target && nums[i] > nums[j]) {
                    if (maxi < nums[i] * nums[j]) {
                        maxi = nums[i] * nums[j];
                        ans[0] = i;
                        ans[1] = j;
                    }
                }
            }
        }

        return ans;
    }
};