class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();

        // arrival time + loading time = finish time
        // finish time , server id
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            busy;

        // all the available servers
        map<int, bool> s;

        vector<int> ans(k, 0);

        for (int i = 0; i < k; i++) {
            s[i] = true;
        }

        for (int i = 0; i < n; i++) {
            long long finish_time = arrival[i] + load[i];
            int need = i % k;

            while (!busy.empty() && busy.top().first <= arrival[i]) {
                s[busy.top().second] = true;
                busy.pop();
            }

            if (s.empty())
                continue;

            auto it = s.lower_bound(need);

            if (it == s.end()) {
                it = s.begin();
            }

            int best_server = it->first;
            // s[best_server] = false;
            s.erase(best_server);

            ans[best_server]++;
            busy.push({finish_time, best_server});
        }

        int maxi = *max_element(ans.begin(), ans.end());
        vector<int> temp;

        for (int i = 0; i < k; i++) {
            if (ans[i] == maxi)
                temp.push_back(i);
        }

        return temp;
    }
};