class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        int range = (n + 1) / 2;

        map<char, int> m;

        for (char c : s) {
            m[c]++;
            if (m[c] > range)
                return "";
        }

        priority_queue<pair<int, char>> pq;

        for (auto& it : m)
            pq.push({it.second, it.first});

        string ans;
        while (pq.size() >= 2) {
            auto one = pq.top();
            pq.pop();
            auto two = pq.top();
            pq.pop();

            ans.push_back(one.second);
            ans.push_back(two.second);

            one.first--;
            if (one.first > 0) {
                pq.push(one);
            }

            two.first--;
            if (two.first > 0) {
                pq.push(two);
            }
        }

        if (!pq.empty()) {
            ans += (pq.top().second);
        }

        return ans;
    }
};