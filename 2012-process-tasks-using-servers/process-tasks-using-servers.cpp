class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int m = servers.size(), n = tasks.size();

        // 2 heaps
        // minheap or set fr available servers { wt, index}
        // busy servers { time , wt , index}

        // server wt , server index
        set<pair<int, int>> available;

        // total time , server wt , server index
        set<tuple<long long, int, int>> busy;

        for (int i = 0; i < m; i++) {
            available.insert({servers[i], i});
        }

        long long time = 0;
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            int cur_task_time = tasks[i];
            time = max(time, (long long)i);

            if (available.empty()) {
                time = max(time, get<0>(*busy.begin()));
            }

            while (!busy.empty() && get<0>(*busy.begin()) <= time) {
                available.insert(
                    {get<1>(*busy.begin()), get<2>(*busy.begin())});
                busy.erase(*busy.begin());
            }

            if (!available.empty()) {
                ans[i] = available.begin()->second;
                busy.insert({time + cur_task_time, available.begin()->first,
                             available.begin()->second});
                available.erase(available.begin());
            }
        }

        return ans;
    }
};