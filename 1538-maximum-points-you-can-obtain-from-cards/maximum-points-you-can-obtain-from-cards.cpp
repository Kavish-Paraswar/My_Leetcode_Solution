class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();

        // int left = 0, right = n - 1;
        int maxi = 0;

        for (int i = 0; i < k; i++) {
            maxi += nums[i];
        }

        int cur_sum = maxi;

        for (int i = 1; i <= k; i++) {
            cur_sum -= nums[k - i];
            cur_sum += nums[n - i];

            maxi = max(maxi, cur_sum);
        }

        return maxi;
    }
};