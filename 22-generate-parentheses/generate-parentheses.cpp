class Solution {
public:
    vector<string> ans;

    void helper(int open, int close, string temp) {

        if (open + close == 0) {
            ans.push_back(temp);
            return;
        }

        if (open > 0) {
            temp.push_back('(');
            helper(open - 1, close, temp);
            temp.pop_back();
        }

        if (close > open) {
            temp.push_back(')');
            helper(open, close - 1, temp);
        }

        // temp.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        int open = n, close = n;

        string temp;
        helper(open, close, temp);

        return ans;
    }
};