class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            long long prod = 1, gcd1 = 0, lcm1 = 1;
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                gcd1 = gcd(gcd1, nums[j]);
                lcm1 = lcm(lcm1, nums[j]);

                if (prod > gcd1 * lcm1)
                    break;

                if (prod == (gcd1 * lcm1))
                    maxi = max(maxi, j - i + 1);
            }
        }

        return maxi;
    }
};