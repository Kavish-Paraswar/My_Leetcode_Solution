class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();

        long long ans = 0;

        // for (int val : nums) {
        //     if (val >= minK && val <= maxK)
        //         ans++;
        // }
        // cout << ans;
        int not_range = 0, left = 0;

        for (int right = 0; right < n; right++) {
            if (!(nums[right] >= minK && nums[right] <= maxK))
                not_range++;

            while (not_range != 0) {
                if (!(nums[left] >= minK && nums[left] <= maxK))
                    not_range--;
                left++;
            }
            // ans++;
            ans += (right - left + 1);
        }

        return ans;
    }
};