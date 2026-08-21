class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        vector<int> ans(m, 0);
        map<int, int> mp;
        stack<int> s;

        for (int i = n - 1; i >= 0; i--) {
            int cur = nums2[i];

            while (!s.empty() && s.top() <= cur)
                s.pop();

            if (s.empty())
                mp[cur] = -1;
            else
                mp[cur] = s.top();

            s.push(nums2[i]);
        }

        for (int i = 0; i < m; i++) {
            ans[i] = mp[nums1[i]];
        }

        return ans;
    }
};