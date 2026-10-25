class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        // if(k == )

        int left = 0, ans = 0, cur_zeros = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0)
                cur_zeros++;

            while (cur_zeros > k) {
                if (nums[left] == 0)
                    cur_zeros--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        // ans = max(ans, n - left - 1);

        return ans;
    }
};