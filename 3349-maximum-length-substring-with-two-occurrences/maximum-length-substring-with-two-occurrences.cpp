class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int left = 0, right = 0;
        map<char, int> m;
        int ans = 0;

        while (right < n) {
            m[s[right]]++;
            while (m[s[right]] > 2) {
                m[s[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};