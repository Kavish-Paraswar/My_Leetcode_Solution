class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1, cnt = 0;
        for (int i = 0; i < n; i++) {
            int r = nums[i] % k;

            if (i > 0 && nums[i - 1] % k == r) {
                cnt++;
            } else {
                cnt = 1;
            }

            if ((1LL * (cnt - 1) * r) % k == 0) {
                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};