class Solution {
public:
    int helper(int cur, int next, vector<vector<int>>& points) {
        int x1 = points[cur][0], y1 = points[cur][1];
        int x2 = points[next][0], y2 = points[next][1];

        return abs(x1 - x2) + abs(y1 - y2);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // edge cost , node{x1,y1}
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0});
        vector<bool> vis(n, false);
        vector<int> costing(n, 1e8);

        int ans = 0;

        while (!pq.empty()) {
            auto [cur_cost, node_id] = pq.top();
            pq.pop();

            if (!vis[node_id]) {
                vis[node_id] = true;
                ans += cur_cost;

                for (int i = 0; i < n; i++) {
                    if (!vis[i]) {
                        int cost = helper(node_id, i, points);

                        if (cost < costing[i]) {
                            costing[i] = cost;
                            ans -= (costing[i] - cost);
                            pq.push({cost, i});
                        }
                    }
                }
            }
        }

        return ans;
    }
};