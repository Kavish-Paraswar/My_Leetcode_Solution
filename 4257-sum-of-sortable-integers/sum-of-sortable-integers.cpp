class Solution {
public:
    vector<int> divisors;
    bool check(vector<int>& nums, int n, int k) {
        int maxi = INT_MIN;
        for (int i = 0; i < n; i += k) {
            int cnd = 0;
            int mini = INT_MAX, cur_max = INT_MIN;

            for (int ptr = i; ptr < i + k; ptr++) {
                int next = i + (ptr - i + 1) % k;
                if (nums[ptr] > nums[next]) {
                    cnd++;
                }

                mini = min(mini, nums[ptr]);
                cur_max = max(cur_max, nums[ptr]);
            }

            if (cnd > 1 || mini < maxi) {
                return false;
            }

            maxi = cur_max;
        }

        return true;
    }
    void helper(int n) {
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisors.push_back(i);

                if (i != n / i)
                    divisors.push_back(n / i);
            }
        }
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        helper(n);

        int ans = 0;
        for (int i = 0; i < divisors.size(); i++) {
            int k = divisors[i];

            if (check(nums, n, k))
                ans += k;
        }

        return ans;
    }
};