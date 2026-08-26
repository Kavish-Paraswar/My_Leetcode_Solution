class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int lefty = 0, righty = 0, cnt = 0, ans = 0;

        while (righty < n) {
            while (righty < n && cnt <= k) {
                if (nums[righty] == 0) {
                    cnt++;
                }
                righty++;
            }

            // if (righty == n)
            //     ans = max(ans, righty - lefty);

            while (lefty < righty && cnt > k) {
                if (nums[lefty] == 0) {
                    cnt--;
                }
                lefty++;

                if(cnt > k)
                    break;
            }

            ans = max(ans, righty - lefty);
        }
        return ans;
    }
};