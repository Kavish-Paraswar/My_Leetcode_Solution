class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();

        int start = 0, maxi = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                start++;
            else if (s[i] == ')')
                start--;
            maxi = max(maxi, start);
        }
        return maxi;
    }
};