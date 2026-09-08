class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[2] != b[2])
            return a[0] < b[0];

        return a[1] < b[1];
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(events.begin(), events.end(), comp);
        int ans = 0;

        vector<int> post_sum(n, 0);
        post_sum[n - 1] = events[n - 1][2];

        for (int i = n - 2; i >= 0; i--) {
            post_sum[i] = max(post_sum[i + 1], events[i][2]);
        }

        for (int i = 0; i < n; i++) {
            int cur = events[i][2], lefty = i + 1, righty = n - 1;
            int pos = n;

            while (lefty <= righty) {
                int mid = lefty + (righty - lefty) / 2;

                if (events[mid][0] > events[i][1]) {
                    pos = mid;
                    righty = mid - 1;
                } else {
                    lefty = mid + 1;
                }
            }

            ans = max(ans, cur);
            if (pos < n)
                ans = max(ans, post_sum[pos] + events[i][2]);
        }

        return ans;
    }
};