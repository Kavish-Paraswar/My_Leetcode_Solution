class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<vector<string>> ans;

        if (n == 0)
            return ans;

        vector<pair<string, int>> s;
        vector<string> temp;

        for (int i = 0; i < n; i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());

            s.push_back({temp, i});
        }

        sort(s.begin(), s.end());

        for (int i = 0; i < n; i++) {

            if (i > 0 && s[i].first != s[i - 1].first) {
                ans.push_back(temp);
                temp.clear();
            }
            temp.push_back(strs[s[i].second]);
        }

        if (!temp.empty())
            ans.push_back(temp);
        return ans;
    }
};