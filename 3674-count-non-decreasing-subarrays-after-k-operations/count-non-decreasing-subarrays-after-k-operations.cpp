class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        long long tot = 1LL * n * (n + 1) / 2;
        long long ans = 0, cost = 0;

        int right = n - 1;
        deque<int> s;

        for (int left = n - 1; left >= 0; left--) {

            while (!s.empty() && nums[s.back()] < nums[left]) {
                int l = s.back();
                s.pop_back();

                int r = s.empty() ? right + 1 : s.back();

                cost += 1LL * (r - l) * (nums[left] - nums[l]);
            }

            s.push_back(left);

            while (cost > k) {
                cost -= nums[s.front()] - nums[right];

                if (s.front() == right)
                    s.pop_front();

                right--;
            }

            ans += n - right - 1;
        }

        return tot - ans;
    }
};