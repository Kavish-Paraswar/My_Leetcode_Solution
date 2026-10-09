class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int left = 0, right = 0;
        map<int, int> m;
        int ans = 0;

        while (right < n) {
            while (m[s[right]] > 0) {
                m[s[left]]--;
                left++;
            }

            m[s[right]]++;
            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};