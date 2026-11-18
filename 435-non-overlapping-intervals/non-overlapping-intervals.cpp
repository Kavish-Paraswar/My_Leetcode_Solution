class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(),
             [](auto& a, auto& b) { return a[1] < b[1]; });
        int cnt = 0, cur_end = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (cur_end <= intervals[i][0]) {
                cur_end = intervals[i][1];
            } else {
                cnt++;
            }
        }
        return cnt;
    }
};