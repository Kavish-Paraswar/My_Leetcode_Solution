class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges,
                vector<int>& passingFees) {

        int n = passingFees.size();

        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // {cost, time, node}
        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>> pq;

        pq.push({passingFees[0], 0, 0});

        vector<vector<int>> cost(n, vector<int>(maxTime + 1, 1e9));

        cost[0][0] = passingFees[0];

        while (!pq.empty()) {
            auto [cur_cost, cur_time, u] = pq.top();
            pq.pop();

            if (cur_cost > cost[u][cur_time])
                continue;

            if (u == n - 1)
                return cur_cost;

            for (auto neigh : adj[u]) {
                int v = neigh.first, z = neigh.second;

                if (cur_time + z <= maxTime) {
                    if (cur_cost + passingFees[v] < cost[v][cur_time + z]) {

                        cost[v][cur_time + z] = cur_cost + passingFees[v];

                        pq.push({cost[v][cur_time + z], cur_time + z, v});
                    }
                }
            }
        }

        return -1;
    }
};