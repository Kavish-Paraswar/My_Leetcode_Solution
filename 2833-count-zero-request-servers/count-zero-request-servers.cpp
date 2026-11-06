class Solution {
public:
    // sliding windows + 2 pointers + sort ??
    static bool cmp(vector<int>& a, vector<int>& b) { return a[1] < b[1]; }
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        int m = logs.size(), o = queries.size();

        vector<vector<int>> query(o, vector<int>(2, 0));
        for (int i = 0; i < o; i++) {
            query[i][0] = queries[i];
            query[i][1] = i;
        }

        sort(logs.begin(), logs.end(), cmp);
        sort(query.begin(), query.end());
        int i = 0, j = 0;
        multiset<int> s;
        vector<int> ans(o, 0);
        int active_servers = 0;

        for (auto& val : query) {
            int cur_query = val[0], idx = val[1];
            int low = cur_query - x;
            int high = cur_query;

            while (j < m && logs[j][1] <= high) {
                int cur_server = logs[j][0];

                if (s.find(cur_server) == s.end())
                    active_servers++;
                s.insert(cur_server);
                j++;
            }

            while (i < j && i < m && logs[i][1] < low) {
                int cur_server = logs[i][0];
                s.erase(s.find(cur_server));

                if (s.find(cur_server) == s.end())
                    active_servers--;

                i++;
            }

            ans[idx] = n - active_servers;
        }

        return ans;
    }
};