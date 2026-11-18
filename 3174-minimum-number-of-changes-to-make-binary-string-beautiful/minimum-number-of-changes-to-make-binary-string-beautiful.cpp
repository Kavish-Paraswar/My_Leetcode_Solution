class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int ans = 0;

        for (int i = 0; i < n - 1; i += 2) {
            ans += (s[i] != s[i + 1]);
        }

        return ans;
    }
};