class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();

        stack<int> s1, s2;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                s1.push(i);

            else if (s[i] == ')') {
                if (!s1.empty())
                    s1.pop();
                else if (!s2.empty()) {
                    s2.pop();
                } else {
                    return false;
                }

            } else {
                s2.push(i);
            }
        }

        while (!s1.empty()) {
            if (s2.empty())
                return false;

            int val = s1.top(), val2 = s2.top();
            s1.pop();
            s2.pop();

            if (val > val2)
                return false;
        }

        return s1.empty();
    }
};