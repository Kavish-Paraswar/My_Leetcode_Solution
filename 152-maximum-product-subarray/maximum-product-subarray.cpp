class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int pref = 1, suf = 1, maxi = nums[0];

        for (int i = 0; i < n; i++) {
            if (pref == 0)
                pref = 1;

            if (suf == 0)
                suf = 1;

            pref = pref * nums[i];
            suf = suf * nums[n - i - 1];

            maxi = max({maxi, pref, suf});
        }

        return maxi;
    }
};