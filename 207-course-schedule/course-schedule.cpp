class Solution {
public:
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

            // if (flag)
            //     return;
        }

        path.erase(cur);
    }
    void topo_sort(vector<vector<int>>& adj) {
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;

        vector<vector<int>> adj(n);

        for (auto& node : prerequisites) {
            adj[node[1]].push_back(node[0]);
        }

        topo_sort(adj);

        return !flag;
    }
};