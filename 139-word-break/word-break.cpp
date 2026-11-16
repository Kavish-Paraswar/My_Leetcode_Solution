class Solution {
public:
    unordered_set<string> set;

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        int maxi = 0;

        for (string& word : wordDict) {
            set.insert(word);
            maxi = max(maxi, (int)word.length());
        }

        // dp[i] tells whether the first i characters can be segmented into
        // dictionary words
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = max(0, i - maxi); j < i; j++) {

                if (dp[j] && set.find(s.substr(j, i - j)) != set.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};