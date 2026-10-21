class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, int>> ans;

        for (int i = 0; i < n; i++) {
            ans.push_back({position[i], speed[i]});
        }

        sort(ans.begin(), ans.end());

        double shortest = -1, fleets = 0;

        for (int i = n - 1; i >= 0; i--) {
            double cur_dist = target - ans[i].first;
            double cur_time = cur_dist / (double)ans[i].second;
            // cout << shortest << "  " << cur_time << endl;
            if (shortest < cur_time) {
                fleets++;
                shortest = cur_time;
            }
        }

        return fleets;
    }
};