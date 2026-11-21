class Solution {
public:
    vector<int> ans;
    string st;
    void dfs(int cur_node, vector<int>& last_seen, vector<vector<int>>& adj,
             vector<int>& parent) {
        int cur = st[cur_node] - 'a';
        int prev = last_seen[cur];
        last_seen[cur] = cur_node;

        ans[cur_node] = 1;

        for (int neigh : adj[cur_node]) {
            dfs(neigh, last_seen, adj, parent);
        }

        if (prev != -1) {
            ans[prev] += ans[cur_node];
        }

        else if (cur_node != 0) {
            ans[parent[cur_node]] += ans[cur_node];
        }

        last_seen[cur] = prev;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        ans.resize(n);
        st = s;

        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> last_seen(26, -1);

        dfs(0, last_seen, adj, parent);

        return ans;
    }
};