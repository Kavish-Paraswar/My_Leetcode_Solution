class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int n = s1.length();
        vector<vector<string>> ans;
        if (s1 == s2)
            return ans;

        string temp1, temp2;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                temp1.push_back(s1[i]);
                temp2.push_back(s2[i]);
            } else {
                if (!temp1.empty()) {
                    ans.push_back({temp1, temp2});
                    temp1 = "";
                    temp2 = "";
                }
            }
        }

        if (!temp1.empty()) {
            ans.push_back({temp1, temp2});
        }

        return ans;
    }
};