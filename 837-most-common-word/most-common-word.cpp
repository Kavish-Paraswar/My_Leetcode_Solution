class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int n = banned.size();

        unordered_map<string, int> m;
        string cur;
        for (char ch : paragraph) {
            if (ispunct(ch) || ch == ' ') {
                if (cur.empty())
                    continue;
                // cout << cur << endl;
                m[cur]++;
                cur = "";
            } else {
                cur.push_back(tolower(ch));
            }
        }

        if (!cur.empty())
            m[cur]++;

        for (int i = 0; i < n; i++) {
            m[banned[i]] = 0;
        }
        int maxi = 0;
        string ans;

        for (auto& it : m) {
            if (it.second > maxi) {
                maxi = it.second;
                ans = it.first;
            }

            cout << it.first << " " << it.second << endl;
        }

        return ans;
    }
};