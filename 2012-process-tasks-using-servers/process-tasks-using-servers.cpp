class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();

        vector<int> ans;

        // 2 min heaps
        //  available - server_weight , server_index

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            available;

        // busy -  finish_time ,server_weight ,  server_index
        priority_queue<tuple<long long, int, int>,
                       vector<tuple<long long, int, int>>,
                       greater<tuple<long long, int, int>>>
            busy;

        for (int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        long long time = 0;

        for (int i = 0; i < m; i++) {

            //
            if (available.empty() && time <= get<0>(busy.top())) {
                time = max(time, get<0>(busy.top()));
            }

            time = max((long long)i, time);

            // pop free servers
            while (!busy.empty() && get<0>(busy.top()) <= time) {
                auto [finish_time, server_weight, server_index] = busy.top();
                available.push({server_weight, server_index});
                busy.pop();
            }
            long long cur_task_time = tasks[i];
            auto [server_weight, server_index] = available.top();
            available.pop();

            busy.push({cur_task_time + time, server_weight, server_index});
            ans.push_back(server_index);
            // time++;
        }

        return ans;
    }
};