class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        int ans = 0;

        for (int i = 0; i <= n; i++) {
            while (!s.empty() && (i == n || heights[s.top()] >= heights[i])) {
                int h = heights[s.top()];
                s.pop();

                int pse = s.empty() ? -1 : s.top();
                int width = i - pse - 1;

                ans = max(ans, h * width);
            }

            if (i < n)
                s.push(i);
        }

        return ans;
    }
};