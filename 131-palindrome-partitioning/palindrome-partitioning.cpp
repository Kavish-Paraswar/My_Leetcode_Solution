class Solution {
public:
    int str_len;
    vector<vector<string>> ans;
    bool check(string a) {
        int n = a.length();

        if (n < 2)
            return true;

        int left = 0, right = n - 1;

        while (left < right) {
            if (a[left] != a[right])
                return false;
            left++;
            right--;
        }

        return true;
    }

    void helper(string s, int i, vector<string>& temp) {

        if (i >= str_len) {
            ans.push_back(temp);
            return;
        }

        for (int k = i; k < str_len; k++) {
            string cur = s.substr(i, k - i + 1);
            if (check(cur)) {
                temp.push_back(cur);

                helper(s, k + 1, temp);

                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        str_len = s.length();
        vector<string> temp;
        helper(s, 0, temp);

        return ans;
    }
};