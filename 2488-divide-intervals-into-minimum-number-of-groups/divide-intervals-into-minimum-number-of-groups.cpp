class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        //    sort(intervals.begin(), interval.end(),
        //  [](auto* a, auto* b) { return a[1] < b[1]; });
        //  gemini vagere noko karu re
        // are maza approach re to heap wala barobar aahe ki nahi check kela

        map<int, int> m;
        m[intervals[0][1]]++;

        for (int i = 1; i < n; i++) {
            int cur_start = intervals[i][0], cur_end = intervals[i][1];
            auto it = m.lower_bound(cur_start);

            if (it != m.begin()) {
                it--;
                it->second--;

                if (it->second == 0)
                    m.erase(it);
                m[cur_end]++;
            } else {
                m[cur_end]++;
            }
        }
        int ans = 0;
        for (auto it : m) {
            ans += it.second;
        }

        return ans;
    }
};

// class Solution {
// public:
//     int minGroups(vector<vector<int>>& intervals) {
//         sort(intervals.begin(), intervals.end());

//         // Key: group end time, Value: number of groups ending at this time
//         map<int, int> m;
//         m[intervals[0][1]]++;
//         int groups = 1;

//         for (int i = 1; i < intervals.size(); i++) {
//             int cur_start = intervals[i][0], cur_end = intervals[i][1];

//             // Check the group that finishes earliest
//             auto it = m.begin();

//             // If it finishes strictly before cur_start, reuse that group
//             if (it->first < cur_start) {
//                 it->second--;
//                 if (it->second == 0) {
//                     m.erase(it);
//                 }
//                 m[cur_end]++;
//             } else {
//                 // Otherwise, all active groups overlap with cur_start; open
//                 a new group m[cur_end]++; groups++;
//             }
//         }

//         return groups;
//     }
// };

// explain me you aprroach
