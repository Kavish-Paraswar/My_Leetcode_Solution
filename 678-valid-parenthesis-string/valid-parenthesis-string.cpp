class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();

        stack<char> s1, s2;

        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '(')
                s1.push(i);
            else if (c == '*')
                s2.push(i);

            else {
                if (s1.empty()) {
                    if (s2.empty())
                        return false;
                    else {
                        s2.pop();
                    }
                } else {
                    s1.pop();
                }
            }
        }

        while (!s1.empty() && !s2.empty()) {
            int val = s1.top(), val2 = s2.top();
            if (val > val2)
                return false;
            s1.pop();
            s2.pop();
        }

        if (!s1.empty())
            return false;
        return true;
    }
};