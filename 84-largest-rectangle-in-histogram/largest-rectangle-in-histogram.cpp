class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 1)
            return heights[0];

        vector<int> nse(n, n);
        stack<int> s;

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            if (!s.empty())
                nse[i] = s.top();
            s.push(i);
        }

        while (!s.empty())
            s.pop();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i])
                s.pop();

            int pse = (s.empty() ? -1 : s.top());

            int temp = heights[i] * (nse[i] - pse - 1);
            // cout << nse[i] << "  " << pse[i] << endl;
            ans = max(ans, temp);
            s.push(i);
        }

        return ans;
    }
};