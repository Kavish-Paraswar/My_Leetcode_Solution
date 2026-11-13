class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        // int n = flights.size();

        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0], v = flights[i][1], wt = flights[i][2];
            adj[u].push_back({v, wt});
        }

        vector<int> dis(n, INT_MAX);
        dis[src] = 0;

        // cur_k, cost , node
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;
        pq.push({0, 0, src});

        while (!pq.empty()) {
            auto [cur_k, cost, u] = pq.top();
            pq.pop();

            if (cur_k == k + 1)
                continue;

            for (auto neigh : adj[u]) {
                int v = neigh.first, edge_wt = neigh.second;

                if (dis[v] > cost + edge_wt) {
                    dis[v] = cost + edge_wt;
                    pq.push({cur_k + 1, dis[v], v});
                }
            }
        }

        if (dis[dst] == INT_MAX)
            return -1;

        return dis[dst];
    }
};