class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());

        long long cur_sum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            cur_sum += nums[i];
            if (cur_sum > 0)
                count++;
        }
        return count;
    }
};