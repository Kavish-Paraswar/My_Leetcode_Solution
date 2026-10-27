class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        map<int, int> m;

        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }

        priority_queue<pair<int, int>> pq;

        for (auto& it : m) {
            pq.push({it.second, it.first});

            // if (pq.size() > k)
            //     pq.pop();
        }

        vector<int> ans;
        int ptr = 0;
        while (ptr < k) {
            ans.push_back(pq.top().second);
            pq.pop();
            ptr++;
        }

        return ans;
    }
};