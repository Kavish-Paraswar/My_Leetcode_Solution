class Solution {
public:
    int sum(int n) {
        int ans = 0;
        while (n > 0) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size(), ans = 0, pos = 0;
        map<int, vector<pair<int, int>>> m;

        for (int i = 0; i < n; i++) {
            m[sum(nums[i])].push_back({nums[i], i});
        }

        vector<int> tar(n);

        for (auto& it : m) {
            sort(it.second.begin(), it.second.end());

            for (auto& p : it.second) {
                tar[p.second] = pos++;
            }
        }

        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                continue;
            }

            int j = i, cnt = 0;

            while (!vis[j]) {
                vis[j] = 1;
                j = tar[j];
                cnt++;
            }

            if (cnt > 1) {
                ans += cnt - 1;
            }
        }

        return ans;
    }
};