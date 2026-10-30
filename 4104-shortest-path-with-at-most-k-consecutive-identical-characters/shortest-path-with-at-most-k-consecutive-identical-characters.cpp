class Solution {
public:
    // TIME generally for djistra is O(ELOGV) and space is O(E+V)
    // here we have to it for all K states for each N
    //  so time will be  O(E * K * log (N * K))
    // and space will be O(E * K  + (N* K))

    typedef tuple<int, int, int> T;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        unordered_map<int, vector<vector<int>>> adjList;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];

            adjList[u].push_back({v, w});
        }

        vector<vector<int>> result(n, vector<int>(k + 1, INT_MAX));
        result[0][1] = 0;

        priority_queue<T, vector<T>, greater<T>> pq;
        // wt,next_node , count
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, node, count] = pq.top();
            pq.pop();

            if (d > result[node][count])
                continue;

            if (node == n - 1)
                return d;

            for (auto& vec : adjList[node]) {
                int adjNode = vec[0], wt = vec[1];

                int newCount =
                    (labels[adjNode] == labels[node]) ? count + 1 : 1;

                if (newCount > k)
                    continue;

                int newDist = d + wt;
                if (newDist < result[adjNode][newCount]) {
                    result[adjNode][newCount] = newDist;
                    pq.push({newDist, adjNode, newCount});
                }
            }
        }

        return -1;
    }
};