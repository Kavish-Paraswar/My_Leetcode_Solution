class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();

        priority_queue<tuple<int, int, int>> pq;

        for (auto point : points) {
            int x = point[0], y = point[1];

            int dis = pow(x, 2) + pow(y, 2);
            // cout << dis << " " << x << " " << y << endl;
            pq.push({dis, x, y});

            if (pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> ans;

        while (!pq.empty()) {
            auto [dis, x, y] = pq.top();
            pq.pop();

            // cout << dis << " " << x << " " << y << endl;
            ans.push_back({x, y});
        }

        return ans;
    }
};