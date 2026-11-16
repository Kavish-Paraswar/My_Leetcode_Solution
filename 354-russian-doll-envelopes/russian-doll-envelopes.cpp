class Solution {
public:
    struct cmp {
        const bool operator()(auto& a, auto& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }

            return a[0] < b[0];
        }
    };
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        sort(envelopes.begin(), envelopes.end(), cmp());

        vector<int> ans;

        ans.push_back(envelopes[0][1]);

        for (int i = 1; i < n; i++) {
            int cur = envelopes[i][1];

            if (cur > ans.back()) {
                ans.push_back(cur);
            } else {
                int lower =
                    lower_bound(ans.begin(), ans.end(), cur) - ans.begin();

                ans[lower] = cur;
            }
        }

        return ans.size();
    }
};