class Solution {
public:
    long long mod = 1000000007, base = 911382323;

    bool check(int size, vector<long long>& h, vector<long long>& p) {
        int n = h.size() - 1;

        unordered_map<long long, int> mp;
        int cnt = 0;

        for (int i = 0; i + size <= n; i++) {
            long long cur = (h[i + size] - h[i] * p[size] % mod + mod) % mod;

            if (mp[cur] == 0)
                cnt++;
            else if (mp[cur] == 1)
                cnt--;

            mp[cur]++;
        }

        return cnt > 0;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<long long> h(n + 1, 0), p(n + 1, 1);

        for (int i = 0; i < n; i++) {
            h[i + 1] = (h[i] * base + nums[i]) % mod;
            p[i + 1] = (p[i] * base) % mod;
        }

        int low = 1, high = n;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (check(mid, h, p))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};