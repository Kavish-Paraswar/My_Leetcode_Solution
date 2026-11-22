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

        vector<int> incoming(n, 0);

        // time , node
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            q;

        for (auto [v, wt] : adj[0]) {
            q.push({wt, v});
        }

        while (!q.empty()) {
            auto [cur_time, u] = q.top();
            q.pop();

            if (ans[u] != -1)
                continue;

            incoming[u]++;

            if (incoming[u] >= requiredSignals[u]) {
                ans[u] = cur_time;

                for (auto& neigh : adj[u]) {
                    int delay_time = neigh.second, v = neigh.first;
                    if (ans[v] == -1)
                        q.push({cur_time + delay_time, v});
                }
            }
        }

        return ans;
    }
};