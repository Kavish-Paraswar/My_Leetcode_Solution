class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        long long ans = 0;

        for (int i = 0; i < n - 1; i++) {
            int mini = nums[i], maxi = nums[i];
            for (int j = i + 1; j < n; j++) {
                mini = min(nums[j], mini);
                maxi = max(maxi, nums[j]);
                ans += (maxi - mini);
            }
        }

        return ans;
    }
};