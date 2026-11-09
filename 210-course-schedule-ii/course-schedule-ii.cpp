class Solution {
public:
    stack<int> s;
    int n;
    bool flag = false;

    void dfs(int cur, vector<bool>& vis, vector<vector<int>>& adj,
             set<int>& path) {
        vis[cur] = true;
        path.insert(cur);

        for (auto& node : adj[cur]) {
            if (!vis[node]) {
                dfs(node, vis, adj, path);
            } else if (path.find(node) != path.end()) {
                flag = true;
                break;
            }

            if (flag)
                return;
        }
        s.push(cur);
        path.erase(cur);
    }
    void topo_sort(vector<int>& ans, vector<vector<int>>& adj) {
        vector<bool> vis(n, false);
        set<int> s;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {

                dfs(i, vis, adj, s);

                if (flag)
                    return;
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;

        vector<vector<int>> adj(n);

        for (auto& node : prerequisites) {
            adj[node[1]].push_back(node[0]);
        }

        vector<int> ans;
        topo_sort(ans, adj);

        if (flag)
            return {};

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};