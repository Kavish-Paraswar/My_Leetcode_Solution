class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int left = 0, ans = 0;
        map<char, int> m;

        for (int right = 0; right < n; right++) {

            char c = s[right];
            while (m[c] > 0) {
                // left++;
                m[s[left++]]--;
            }
            m[s[right]]++;
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
