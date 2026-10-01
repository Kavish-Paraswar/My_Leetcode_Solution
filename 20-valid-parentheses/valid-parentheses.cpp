class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if (n % 2 == 1)
            return false;

        stack<char> c;

        for (int i = 0; i < n; i++) {
            char cur = s[i];

            if (cur == '(' || cur == '[' || cur == '{') {
                c.push(cur);
            } else {

                if (c.empty())
                    return false;

                char last = c.top();
                if ((last == '(' && cur == ')') ||
                    (last == '[' && cur == ']') ||
                    (last == '{' && cur == '}')) {
                    c.pop();
                } else {
                    return false;
                }
            }
        }
        return c.empty();
    }
};