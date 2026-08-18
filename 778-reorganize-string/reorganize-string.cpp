class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        int limit = (n + 1) / 2;

        map<char, int> m;
        int maxi = 0;

        for (char& c : s) {
            m[c]++;
            maxi = max(maxi, m[c]);
        }

        if (maxi > limit)
            return "";

        priority_queue<pair<int, char>> maxi_heap;

        for (auto& pair : m) {
            maxi_heap.push({pair.second, pair.first});
        }

        string ans;

        while (maxi_heap.size() >= 2) {
            auto first = maxi_heap.top();
            maxi_heap.pop();
            auto second = maxi_heap.top();
            maxi_heap.pop();

            ans += first.second;
            ans += second.second;

            first.first--;
            if (first.first > 0) {
                maxi_heap.push({first.first, first.second});
            }
            second.first--;
            if (second.first > 0) {
                maxi_heap.push({second.first, second.second});
            }
        }

        if (!maxi_heap.empty()) {
            auto last = maxi_heap.top();
            ans += last.second;
        }

        return ans;
    }
};