class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<vector<string>> ans;

        if (n == 0)
            return ans;

        unordered_map<string, vector<string>> mp;

        for (auto& str : strs) {
            vector<int> freq(26, 0);

            for (char c : str) {
                freq[c - 'a']++;
            }

            string key;

            for (int x : freq) {
                key += to_string(x) + '#';
            }

            mp[key].push_back(str);
        }

        for (auto& it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};