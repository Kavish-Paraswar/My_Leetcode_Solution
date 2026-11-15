class Solution {
public:
    struct cmp {
        const bool operator()(auto& a, auto& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> freq;

        for (string& s : words) {
            freq[s]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;

        for (auto& it : freq) {
            pq.push({it.second, it.first});
        }

        vector<string> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};