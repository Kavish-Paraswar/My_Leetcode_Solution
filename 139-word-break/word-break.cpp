class Solution {
public:
    unordered_set<string> set;

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        for (string& word : wordDict)
            set.insert(word);

        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {

                if (dp[j] && set.find(s.substr(j, i - j)) != set.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};