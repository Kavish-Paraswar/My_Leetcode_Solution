class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();

        sort(meetings.begin(), meetings.end());
        vector<int> ans(n, 0);

        // min heap { ending _time , room id}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            busy;

        // all the avaialable rooms
        set<int> s;

        for (int i = 0; i < n; i++) {
            s.insert(i);
        }

        for (int i = 0; i < m; i++) {

            long long tot_dur = meetings[i][1] - meetings[i][0];

            while (!busy.empty() && busy.top().first <= meetings[i][0]) {
                s.insert(busy.top().second);
                busy.pop();
            }

            if (!s.empty()) {
                int lowest_room = *s.begin();
                ans[lowest_room]++;

                busy.push({meetings[i][1], lowest_room});
                s.erase(s.begin());
            } else {
                long long cur_time = busy.top().first;
                int free_room_id = busy.top().second;

                busy.pop();
                busy.push({cur_time + tot_dur, free_room_id});
                ans[free_room_id]++;
            }
        }

        int maxi = *max_element(ans.begin(), ans.end());

        for (int i = 0; i < n; i++) {
            if (maxi == ans[i])
                return i;
        }

        return -1;
    }
};