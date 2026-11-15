class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        set<vector<int>> s;

        vector<vector<int>> ans;

        for (int i = 0; i < n - 2; i++) {
            int start = i + 1, end = n - 1;

            while (start < end) {
                int cur_sum = nums[i] + nums[start] + nums[end];

                if (cur_sum == 0) {
                    s.insert({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                } else if (cur_sum > 0) {
                    end--;
                } else {
                    start++;
                }
            }
        }

        return vector<vector<int>>(s.begin(), s.end());
    }
};