class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(), q = p.length();

        if (q > n)
            return {};

        vector<int> m(26, 0);
        vector<int> ans;
        int maxi = 0;

        for (char& c : p) {
            m[c - 'a']++;
            // maxi = max(maxi, m[c]);
        }
        // int zeros = 0;
        int left = 0;

        vector<int> cur(26, 0);

        for (int right = 0; right < n; right++) {

            cur[s[right] - 'a']++;

            while (right - left + 1 >= q && cur != m) {
                cur[s[left] - 'a']--;
                left++;
            }
            if ((right - left + 1) == q)
                ans.push_back(left);
        }

        return ans;
    }
};