class Solution {
public:
    //  bro , we have to do dijstra with {time , passingfee , node }
    // are passing fee garaj nahi na
    // we have to return min passingfree for that path
    // no we need to return teh minimmum cost to complete you journey
    // here the cost = passingfees

    int minCost(int maxTime, vector<vector<int>>& edges,
                vector<int>& passingFees) {

        int n = passingFees.size();

        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        //  {cost = passingfee , time , node }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;
        pq.push({passingFees[0], 0, 0});

        vector<vector<int>> cost(n, vector<int>(maxTime + 1, 1e8));
        cost[0][0] = passingFees[0];

        while (!pq.empty()) {
            auto [cur_cost, cur_time, u] = pq.top();
            pq.pop();

            if (cur_cost > cost[u][cur_time])
                continue;

            if (u == n - 1) {
                return cur_cost;
            }

            for (auto neigh : adj[u]) {
                int v = neigh.first, time = neigh.second;
                int nt = cur_time + time;
                int nc = cur_cost + passingFees[v];

                if (nt <= maxTime && nc < cost[v][nt]) {
                    cost[v][nt] = nc;
                    pq.push({nc, nt, v});
                }
            }
        }

        // for (int i = 0; i < n; i++) {
        //     cout << cost[i] << " ";
        // }
        // if (cost[n - 1] == 1e8)
        //     return -1;

        return -1;
    }
};

// maxTime =
// 10
// edges =
// [[0,1,2],[0,2,1],[0,3,10],[1,3,2],[3,2,2],[4,3,1]]
// passingFees =
// [1,1,3,2,1]
// cost[i] = 1 2 4 3 100000000
// Output
// -1
// Expected
// 5
