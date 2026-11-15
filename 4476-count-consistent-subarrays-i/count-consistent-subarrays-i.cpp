class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size();

        int count = 0;
        int bitwise, mini;

        for (int i = 0; i < n; i++) {
            bitwise = nums[i], mini = nums[i];
            for (int j = i; j < n; j++) {
                bitwise = bitwise & nums[j];
                mini = min(mini, nums[j]);
                if (bitwise == mini) {
                    count++;
                }
            }
        }

        return count;
    }
};