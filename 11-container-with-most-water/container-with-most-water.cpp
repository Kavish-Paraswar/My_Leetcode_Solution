class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int i = 0, j = n - 1, maxi = 0;

        while (i < j) {
            int cur_h;
            if (height[i] < height[j]) {
                cur_h = height[i];
                i++;
            } else {
                cur_h = height[j];
                j--;
            }

            int cur_area = (j - i + 1) * cur_h;
            maxi = max(maxi, cur_area);
        }

        return maxi;
    }
};