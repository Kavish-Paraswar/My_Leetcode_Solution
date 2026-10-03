class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int ptr2 = n - 1, ptr1 = 0;

        while (ptr1 < m && ptr2 >= 0) {
            int cur = matrix[ptr1][ptr2];

            if (cur == target) {
                return true;
            } else if (cur > target) {
                ptr2--;
            } else {
                ptr1++;
            }
        }
        return false;
    }
};