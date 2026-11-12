class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int increasing = 1, decreasing = 1;
        int maxi = 1;

        for (int i = 0; i < n - 1; i++) {   
            if (nums[i] > nums[i + 1]) {
                increasing++;
                maxi = max({maxi, increasing, decreasing});
                decreasing = 1;

            } else if (nums[i] == nums[i + 1]) {
                maxi = max({maxi, increasing, decreasing});
                increasing = 1;
                decreasing = 1;
            } else {
                decreasing++;
                maxi = max({maxi, increasing, decreasing});
                increasing = 1;
            }
        }

        return maxi;
    }
};