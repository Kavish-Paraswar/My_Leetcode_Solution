class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // vector<bool> vis(n, false);
        // vis[0] = true;
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            if (maxi < i)
                return false;

            maxi = max(maxi, i + nums[i]);
        }

        return true;
    }
};