class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> next(n, -1), prev(n, -1);

        next[n - 1] = height[n - 1];
        prev[0] = height[0];

        for (int i = 1; i < n; i++) {
            prev[i] = max(prev[i - 1], height[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            next[i] = max(next[i + 1], height[i]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int next_grt = next[i];
            int prev_grt = prev[i];

            int h = min(next_grt, prev_grt);
            ans += h - height[i];
        }

        return ans;
    }
};