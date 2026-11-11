class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto& val : times) {
            adj[val[0]].push_back({val[1], val[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, k});

        vector<int> dist(n + 1, INT_MAX);
        dist[0] = 0;
        dist[k] = 0;

        while (!pq.empty()) {
            auto [cost, cur_node] = pq.top();
            pq.pop();

            for (auto& node : adj[cur_node]) {
                if (dist[node.first] > dist[cur_node] + node.second) {
                    dist[node.first] = dist[cur_node] + node.second;
                    pq.push({dist[node.first], node.first});
                }
            }
        }

        int maxi = *max_element(dist.begin(), dist.end());

        if (maxi == INT_MAX) {
            return -1;
        }

        return maxi;
    }
};