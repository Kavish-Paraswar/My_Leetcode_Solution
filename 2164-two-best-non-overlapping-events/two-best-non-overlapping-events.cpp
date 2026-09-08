class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[2] != b[2])
            return a[2] > b[2];

        return a[0] < b[0];
    }

    static bool comp2(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0])
            return a[0] < b[0];

        return a[1] < b[1];
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        vector<vector<int>> v = events;

        sort(events.begin(), events.end(), comp);
        sort(v.begin(), v.end(), comp2);

        vector<int> maxi(n);
        maxi[n - 1] = v[n - 1][2];

        for (int i = n - 2; i >= 0; i--)
            maxi[i] = max(maxi[i + 1], v[i][2]);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int cur = events[i][2];
            int cur_end = events[i][1];

            int lefty = 0;
            int righty = n - 1;
            int pos = n;

            while (lefty <= righty) {
                int mid = lefty + (righty - lefty) / 2;

                if (v[mid][0] > cur_end) {
                    pos = mid;
                    righty = mid - 1;
                } else {
                    lefty = mid + 1;
                }
            }

            ans = max(ans, cur);

            if (pos < n)
                ans = max(ans, cur + maxi[pos]);
        }

        return ans;
    }
};