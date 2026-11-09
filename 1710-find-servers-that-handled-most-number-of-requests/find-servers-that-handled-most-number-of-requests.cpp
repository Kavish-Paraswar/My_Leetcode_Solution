class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();

        // finish _time , server no
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            q;
        // free server nos
        set<int> s;

        vector<int> ans(k, 0);

        for (int i = 0; i < k; i++) {
            s.insert(i);
        }

        for (int i = 0; i < n; i++) {
            long long cur_arrival = arrival[i];
            long long cur_load = load[i];
            int need = i % k;

            while (!q.empty() && q.top().first <= cur_arrival) {
                s.insert(q.top().second);
                q.pop();
            }

            if (s.empty())
                continue;

            auto it = s.lower_bound(need);

            if (it == s.end())
                it = s.begin();

            int top_server = *it;
            s.erase(top_server);

            ans[top_server]++;
            q.push({cur_arrival + 1LL * cur_load, top_server});
        }

        vector<int> temp;
        int maxi = *max_element(ans.begin(), ans.end());

        for (int i = 0; i < k; i++) {
            if (ans[i] == maxi)
                temp.push_back(i);
        }

        return temp;
    }
};