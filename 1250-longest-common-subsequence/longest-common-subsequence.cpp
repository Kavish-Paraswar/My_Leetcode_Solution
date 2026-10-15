class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // if (m > n)
        //     swap(text1, text2);

        for (int ptr1 = 1; ptr1 <= n; ptr1++) {
            for (int ptr2 = 1; ptr2 <= m; ptr2++) {
                int op1 = 0, op2 = 0;
                if (text1[ptr1 - 1] == text2[ptr2 - 1]) {
                    dp[ptr1][ptr2] = 1 + dp[ptr1 - 1][ptr2 - 1];
                } else {
                    op1 = dp[ptr1 - 1][ptr2];
                    op2 = dp[ptr1][ptr2 - 1];
                }
                dp[ptr1][ptr2] = max({dp[ptr1][ptr2], op1, op2});
            }
        }

        return dp[n][m];
    }
};