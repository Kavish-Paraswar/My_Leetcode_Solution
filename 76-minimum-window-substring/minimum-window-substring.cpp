class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        if (s == t)
            return s;
        if (n > m)
            return "";

        map<char, int> freq;

        for (int i = 0; i < n; i++) {
            freq[t[i]]++;
        }

        int left = 0, mini = INT_MAX, zeros = 0, start = 0;

        for (int right = 0; right < m; right++) {
            if (freq.find(s[right]) != freq.end()) {
                freq[s[right]]--;
                zeros += (freq[s[right]] == 0);
            }

            while (zeros == freq.size()) {
                if (mini > (right - left + 1)) {
                    mini = right - left + 1;
                    start = left;
                }
                if (freq.find(s[left]) != freq.end()) {
                    freq[s[left]]++;
                    zeros -= (freq[s[left]] > 0);
                }
                left++;
            }
        }

        if (mini == INT_MAX)
            return "";

        return s.substr(start, mini);
    }
};