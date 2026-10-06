class Solution {
public:
    string processStr(string s) {
        int n = s.length();
        string ans;

        for (char& c : s) {
            if (c == '*' && ans.length() > 0) {
                ans.erase(ans.end() - 1, ans.end());
            } else if (c == '#') {
                ans.append(ans);
            } else if (c == '%') {
                reverse(ans.begin(), ans.end());
            } else if (c >= 'a' && c <= 'z') {
                ans.push_back(c);
            }
        }

        return ans;
    }
};