class Solution {
public:
    struct cmp {
        const bool operator()(auto& a, auto& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        for (string& s : words) {
            freq[s]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;

        for (auto& it : freq) {
            pq.push({it.second, it.first});

            if (pq.size() > k)
                pq.pop();
        }

        vector<string> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};