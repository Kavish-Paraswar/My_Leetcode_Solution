class Solution {
public:
    vector<vector<int>> ans;
    int n;

    void helper(vector<int>& temp, vector<int>& nums, int i) {
        if (i == n) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        helper(temp, nums, i + 1);

        temp.pop_back();
        helper(temp, nums, i + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();

        vector<int> temp;
        // ans.push_back({});
        // ans.push_back();
        helper(temp, nums, 0);

        return ans;
    }
};