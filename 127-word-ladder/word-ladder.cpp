class Solution {
public:
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

        while (!q.empty()) {
            auto obj = q.front();
            string cur_str = obj.first;
            int score = obj.second;
            q.pop();

            if (cur_str == endWord) {
                return score;
            }

            for (int i = 0; i < cur_str.length(); i++) {
                char original = cur_str[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == original)
                        continue;

                    cur_str[i] = ch;

                    if (set.find(cur_str) != set.end()) {
                        q.push({cur_str, score + 1});
                        set.erase(cur_str);
                    }
                }
                cur_str[i] = original;
            }
            // if (count == 1e9)
        }
        return 0;
    }
};