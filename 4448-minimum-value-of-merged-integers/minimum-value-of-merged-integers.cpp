class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        for (int i = 0; i < n - 1; i += 2) {
            int power = to_string(nums[i + 1]).length();

            int temp = nums[i] * round(pow(10, power)) + nums[i + 1];

            // temp = nums[i] * 10 + nums[i + 1];

            mini = min(mini, temp);
        }

        return mini;
    }
};