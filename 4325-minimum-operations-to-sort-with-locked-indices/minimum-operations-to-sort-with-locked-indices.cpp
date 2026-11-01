class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();

        vector<int> pref_sum(n + 1, 0);
        // pref_sum[0] = locked[0];

        for (int i = 0; i < n; i++) {
            pref_sum[i + 1] = pref_sum[i] + locked[i];
        }

        int maxi = 0;
        int needed = 0, left = 0;

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);

            if (maxi == i + 1) {
                if (i > left) {
                    int have = pref_sum[i + 1] - pref_sum[left];
                    needed += have;
                }
                left = i + 1;
            }
            if (needed > k)
                return -1;
        }

        int swap = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] > nums[j])
                    swap++;
            }
        }

        return swap + needed;
    }
};