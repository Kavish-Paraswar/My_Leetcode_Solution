class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                sum += nums[i];
            else if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1])
                sum -= nums[i];
        }

        return sum;
    }
};