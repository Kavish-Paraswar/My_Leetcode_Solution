class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();

        long long ans = LLONG_MAX;

        for (int i = 1; i < n - 1; i++) {
            int cur = nums[i];

            int ptr = i;
            while (ptr > 0 && nums[ptr] == nums[ptr - 1])
                ptr--;

            int ptr2 = i;
            while (ptr2 < n - 1 && nums[ptr2] == nums[ptr2 + 1])
                ptr2++;

            long long cost = 0;

            long long prefix = 1LL * ptr * cur;
            long long suffix = 1LL * (n - ptr2 - 1) * cur;
            cost = prefix + suffix;

            ans = min(ans, cost);
            i = ptr2;
        }

        return ans;
    }
};