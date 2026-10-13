class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> bits(32, 0);

        for (int val : nums) {
            for (int i = 0; i < 32; i++) {
                if (val & 1)
                    bits[i] += 1;
                val = val >> 1;
            }
        }

        // for (int val : bits) {
        //     cout << val << " ";
        // }

        int MOD = 1e9 + 7;
        long long ans = 0;

        for (int j = 0; j < k; j++) {
            long long temp = 0;
            for (int i = 31; i >= 0; i--) {
                if (bits[i] > 0) {
                    temp = (temp << 1) | 1;
                    bits[i]--;
                    // cout << temp << endl;
                } else {
                    temp = temp << 1;
                }
            }
            long long cur_val = (temp * temp) % MOD;
            ans = (ans + cur_val) % MOD;
        }
        return (int)ans;
    }
};