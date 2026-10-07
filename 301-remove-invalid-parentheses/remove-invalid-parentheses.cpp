class Solution {
public:
    set<string> set;
    int n;
    bool check(string s) {
        int bal = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                bal++;
            } else if (s[i] == ')') {
                if (bal == 0) {
                    return false;
                } else
                    bal--;
            }
        }
        return bal == 0;
    }

    void helper(string s, string temp, int opening, int closing, int ind) {
        int temp_size = temp.length();
        if (ind > temp_size || (temp_size - ind) < opening + closing)
            return;

        if (opening == 0 && closing == 0) {
            if (check(temp))
                set.insert(temp);
            return;
        }

        // s.erase(ind, 1);
        for (int i = ind; i < temp.length(); i++) {
            // temp = s;
            if (temp[i] == '(' && opening > 0) {
                string next = temp;
                next.erase(i, 1);
                helper(s, next, opening - 1, closing, i);
            } else if (temp[i] == ')' && closing > 0) {
                string next = temp;
                next.erase(i, 1);
                helper(s, next, opening, closing - 1, i);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        n = s.length();
        int closing = 0, bal = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                bal++;
            } else if (s[i] == ')') {
                if (bal == 0) {
                    closing++;
                } else
                    bal--;
            }
        }

        int opening = bal;
        string temp = s;

        helper(s, temp, opening, closing, 0);

        vector<string> ans;

        for (auto& temp : set) {
            ans.push_back(temp);
        }

        return ans;
    }
};