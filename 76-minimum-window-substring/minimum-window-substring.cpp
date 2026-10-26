class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        if (s == t)
            return s;
        if (n > m)
            return "";

        vector<int> freq(128, 0);

        for (int i = 0; i < n; i++) {
            freq[t[i]]++;
        }

        int left = 0, mini = INT_MAX, zeros = 0, start = 0;

        for (int right = 0; right < m; right++) {
            if (freq[s[right]] > 0) {
                zeros++;
            }
            freq[s[right]]--;

            while (zeros == n) {
                if (mini > (right - left + 1)) {
                    mini = right - left + 1;
                    start = left;
                }

                freq[s[left]]++;
                zeros -= (freq[s[left]] > 0);
                left++;
            }
        }

        if (mini == INT_MAX)
            return "";

        return s.substr(start, mini);
    }
};