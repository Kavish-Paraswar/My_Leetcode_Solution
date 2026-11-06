class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        int cnt = count(nums.begin(), nums.end(), 1);
        if (cnt == 0)
            return 0;
        int cur_cnt = 0;

        for (int i = 0; i < cnt; i++) {
            if (nums[i] == 1)
                cur_cnt++;
        }
        int maxi = -1;

        for (int i = cnt; i < n + cnt - 1; i++) {
            maxi = max(maxi, cur_cnt);
            int left = (i - cnt) % n;
            int right = i % n;

            if (nums[left] == 1) {
                cur_cnt--;
            }
            if (nums[right] == 1)
                cur_cnt++;
        }

        maxi = max(maxi, cur_cnt);
        // if (cnt == maxi)
        //     return 1;
        return cnt - maxi;
    }
};