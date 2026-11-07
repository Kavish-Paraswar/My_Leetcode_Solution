class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        vector<int> ans(m, 0);

        // 2 heaps for available and best server possible
        // and next one for smalelst rem time we can need to wait
        // wt , index
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            available;
        // {finish_time, {weight, index}}
        priority_queue<tuple<long long, int, int>,
                       vector<tuple<long long, int, int>>,
                       greater<tuple<long long, int, int>>>
            busy;

        for (int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        long long time = 0;

        for (int i = 0; i < m; i++) {
            long long cur_task_time = tasks[i];
            time = max(time, (long long)i);

            if (available.empty()) {
                time = max(time, std::get<0>(busy.top()));
            }

            while (!busy.empty() && get<0>(busy.top()) <= time) {
                available.push({std::get<1>(busy.top()), get<2>(busy.top())});
                busy.pop();
            }

            if (!available.empty()) {
                // auto
                ans[i] = available.top().second;
                busy.push(
                    {cur_task_time + time, available.top().first, ans[i]});
                available.pop();
            }
        }

        return ans;
    }
};