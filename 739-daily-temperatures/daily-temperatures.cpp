class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
                int ind = s.top();
                s.pop();
                ans[ind] = abs(ind - i);
            }
            s.push(i);
        }

        return ans;
    }
};