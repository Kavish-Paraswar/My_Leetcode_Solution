class Solution {
public:
    int num;
    stack<int> s;

    void dfs(int cur, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[cur] = true;

        for (auto& val : adj[cur]) {
            if (!vis[val])
                dfs(val, adj, vis);
        }

        s.push(cur);
    }

    void helper(vector<int>& topo_sort, vector<vector<int>>& adj) {
        vector<bool> vis(num, false);

        for (int i = 0; i < num; i++) {
            if (!vis[i])
                dfs(i, adj, vis);
        }

        while (!s.empty()) {
            topo_sort.push_back(s.top());
            s.pop();
        }
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        num = n;

        vector<vector<int>> adj(n);

        for (auto val : relations) {
            int u = val[0] - 1, v = val[1] - 1;
            adj[v].push_back(u);
        }

        vector<int> topo_sort;

        helper(topo_sort, adj);

        vector<int> dp(n, 0);

        for (int j = n - 1; j >= 0; j--) {
            int cur = topo_sort[j];
            int temp = 0;
            for (auto& val : adj[cur]) {
                temp = max(temp, dp[val]);
            }
            dp[cur] = time[cur] + temp;
        }

        return *max_element(dp.begin(), dp.end());
    }
};