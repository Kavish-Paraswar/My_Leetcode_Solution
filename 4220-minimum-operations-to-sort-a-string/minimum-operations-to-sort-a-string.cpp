class Solution {
public:
    int minOperations(string s) {
        if (is_sorted(s.begin(), s.end()))
            return 0;

        int n = s.length();
        if (n == 2)
            return -1;

        char maxi = 'a', mini = 'z';
        int maxi_ind = 0, mini_ind = 0;

        for (int i = 0; i < n; i++) {
            char cur = s[i];

            if (maxi - cur < 0) {
                maxi = cur;
                maxi_ind = i;
            }
            if (mini - cur > 0) {
                mini = cur;
                mini_ind = i;
            }
        }

        if (mini == s[0] || maxi == s[n - 1])
            return 1;

        for (int i = 1; i < n - 1; i++) {
            if (s[i] == mini || s[i] == maxi)
                return 2;
        }

        return 3;
    }
};