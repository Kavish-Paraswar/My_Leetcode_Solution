class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans = {{}};

        for (int i = 0; i < n; i++) {
            int cur = ans.size();
            for (int j = 0; j < cur; j++) {
                vector<int> temp = ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }

        return ans;
    }
};