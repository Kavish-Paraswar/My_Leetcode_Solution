class Solution {
public:
    long long dfs(int node, vector<vector<int>>& adj, vector<int>& op,
                  vector<int>& score) {

        if (adj[node].empty()) {
            return score[node];
        }

        long long sum = 0, mini = LLONG_MAX;
        for (auto neigh : adj[node]) {
            long long sum_childs = dfs(neigh, adj, op, score);
            sum += sum_childs;
            mini = min(mini, sum_childs);
        }

        if (op[node] == 0) {
            mini = min(0LL, mini);
        }
        return score[node] + sum - mini;
    }
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n = parent.size();

        if (n == 1)
            return score[0];

        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        return (int)dfs(0, adj, op, score);
    }
};