class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int target = 0;

        if (n % 2 == 1) {
            target = nums[(n / 2)];
        }

        else {
            target = (nums[n / 2 - 1] + nums[n / 2]) / 2;
        }

        int ans = 0;

        for (int& val : nums) {
            ans += abs(val - target);
        }

        return ans;
    }
};