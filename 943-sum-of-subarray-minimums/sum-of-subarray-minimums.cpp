class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size(), MOD = 1e9 + 7;
        vector<int> left(n), right(n);
        stack<int> s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums[s.top()] > nums[i])
                s.pop();

            left[i] = (s.empty()) ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty())
            s.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] >= nums[i])
                s.pop();

            right[i] = (s.empty()) ? n : s.top();
            s.push(i);
        }
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long lefty = i - left[i];
            long long righty = right[i] - i;

            long long temp = (lefty * righty * nums[i]) % MOD;
            ans = (ans + temp) % MOD;
        }

        return ans;
    }
};