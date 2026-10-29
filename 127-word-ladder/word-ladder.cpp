class Solution {
public:
    bool check(string a, string b) {
        int mis = 0;

        for (int i = 0; i < a.length(); i++)
            if (a[i] != b[i])
                mis++;

        return mis <= 1;
    }

    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        int n = wordList.size();

        unordered_set<string> set;
        for (string& c : wordList) {
            set.insert(c);
        }

        if (set.find(endWord) == set.end())
            return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        // int count = 1e9;

        while (!q.empty()) {
            auto obj = q.front();
            string cur_str = obj.first;
            int score = obj.second;
            q.pop();

            if (cur_str == endWord) {
                return score;
            }

            for (string& temp : wordList) {
                if (temp == cur_str)
                    continue;

                if (set.find(temp) != set.end() && check(temp, cur_str)) {
                    q.push({temp, score + 1});
                    set.erase(temp);
                }
            }
        }

        // if (count == 1e9)
        return 0;
    }
};