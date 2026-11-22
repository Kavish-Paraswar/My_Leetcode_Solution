class Solution {
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges,
                                              vector<int>& requiredSignals) {
        vector<long long> ans(n, -1);
        ans[0] = 0;

        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], delay = edges[i][2];
            adj[u].push_back({v, delay});
        }

        unordered_map<int, unordered_set<int>> incoming;

        // time , u , v
        priority_queue<tuple<long long, int, int>,
                       vector<tuple<long long, int, int>>,
                       greater<tuple<long long, int, int>>>
            q;

        for (auto [v, wt] : adj[0]) {
            q.push({wt, 0, v});
        }

        while (!q.empty()) {
            auto [cur_time, u, v] = q.top();
            q.pop();

            if (ans[v] != -1)
                continue;

            incoming[v].insert(u);

            if (incoming[v].size() >= requiredSignals[v]) {
                ans[v] = cur_time;

                for (auto& neigh : adj[v]) {
                    int delay_time = neigh.second, w = neigh.first;
                    if (ans[w] == -1)
                        q.push({cur_time + delay_time, v, w});
                }
            }
        }

        return ans;
    }
};