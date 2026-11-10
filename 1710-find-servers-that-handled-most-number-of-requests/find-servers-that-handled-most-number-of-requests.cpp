class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        int n = arrival.size();
        vector<int> ans(k, 0);

        // min heap - busy - finish_time , server id
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            busy;

        // set to have available server
        set<int> available;

        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        for (int i = 0; i < n; i++) {
            long long cur_time = arrival[i] + load[i];

            while (!busy.empty() && busy.top().first <= arrival[i]) {
                available.insert(busy.top().second);
                busy.pop();
            }

            if (available.empty())
                continue;

            int need = i % k;
            auto it = available.lower_bound(need);

            if (it == available.end())
                it = available.begin();

            int allocating_server = *it;
            ans[allocating_server]++;

            busy.push({cur_time, allocating_server});
            available.erase(allocating_server);
        }

        vector<int> temp;
        int maxi = *max_element(ans.begin(), ans.end());

        for (int i = 0; i < k; i++) {
            if (maxi == ans[i])
                temp.push_back(i);
        }

        return temp;
    }
};