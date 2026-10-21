class Solution {
public:
    int maxi_area(vector<int>& ans, int cols) {
        int maxi = 0;
        stack<int> s;

        for (int i = 0; i <= cols; i++) {
            while (!s.empty() && (i == cols || ans[s.top()] >= ans[i])) {
                int h = ans[s.top()];
                s.pop();

                int pse = s.empty() ? -1 : s.top();
                int width = i - pse - 1;
                int side = min(width, h);
                maxi = max(maxi, side * side);
            }
            if (i < cols)
                s.push(i);
        }

        return maxi;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();

        vector<int> ans(cols, 0);
        int maxi2 = 0;

        for (int i = 0; i < rows; i++) {
            int cur = 0;
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    ans[j]++;
                else {
                    ans[j] = 0;
                }
            }
            maxi2 = max(maxi2, maxi_area(ans, cols));
        }

        return maxi2;
    }
};
