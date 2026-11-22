class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;

        int cnt = 0;

        for (int i = 1; i < n - 1; i++) {
            double cur = nums[i];
            double avg = (double(nums[i - 1] + nums[i + 1])) / 2;

            if (cur >= avg) {
                cnt++;
            }
        }

        cnt += (nums[0] >= nums[1]);
        cnt += (nums[n - 1] >= nums[n - 2]);

        return cnt;
    }
};