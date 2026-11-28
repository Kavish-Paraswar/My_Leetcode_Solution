
class Solution {
public:
    vector<int> helper(vector<vector<int>>& items) {
        vector<int> freebies;
        int maxi = 0;

        for (auto& item : items)
            maxi = max(maxi, item[0]);

        vector<int> freq(maxi + 1, 0);

        for (auto& item : items)
            freq[item[0]]++;

        for (auto& item : items) {
            int factor = item[0];
            int cnt = 0;

            for (int k = factor; k <= maxi; k += factor) {
                cnt += freq[k];

                if (k == factor)
                    cnt--;
            }

            freebies.push_back(cnt);
        }

        return freebies;
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freebies = helper(items);

        vector<pair<int, int>> v;
        int mini = INT_MAX;

        for (int i = 0; i < n; i++) {
            v.push_back({items[i][1], freebies[i]});
            mini = min(mini, items[i][1]);
        }

        sort(v.begin(), v.end());

        long long ans = 0;
        long long rem = budget;

        for (auto& p : v) {
            long long price = p.first;
            long long cnt = p.second;

            if (price > 2LL * mini)
                break;

            long long take = min(cnt, rem / price);

            ans += 2 * take;
            rem -= take * price;
        }

        ans += rem / mini;

        return ans;
    }
};
