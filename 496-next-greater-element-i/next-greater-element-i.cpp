class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        stack<int> s;
        map<int, int> mp;

        for (int i = m - 1; i >= 0; i--) {
            int cur = nums2[i];

            while (!s.empty() && s.top() <= cur)
                s.pop();

            if (s.empty()) {
                mp[cur] = -1;
            } else {
                mp[cur] = s.top();
            }
            s.push(nums2[i]);
        }
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            ans[i] = mp[nums1[i]];
        }

        return ans;
    }
};