class Solution {
public:
    vector<long long> helper(vector<int>& nums, int i, int j) {
        long long prod = nums[i], gcd1 = nums[i], lcm1 = nums[i];

        for (int k = i + 1; k <= j; k++) {
            prod *= nums[k];

            gcd1 = gcd(gcd1, nums[k]);
            lcm1 = lcm(lcm1, nums[k]);
            if (prod > gcd1 * lcm1)
                return {-1, -1, -1};
        }

        return {prod, gcd1, lcm1};
    }
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                vector<long long> temp = helper(nums, i, j);
                long long prod = temp[0], gcd = temp[1], lcm = temp[2];

                if (prod == -1)
                    break;
                if (prod == (gcd * lcm))
                    maxi = max(maxi, j - i + 1);
            }
        }

        return maxi;
    }
};