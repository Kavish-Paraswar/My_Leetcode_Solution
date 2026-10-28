class Solution {
public:
    vector<vector<int>> ans;
    int n;

    void helper(vector<int> temp, vector<int>& nums, int i) {
        if (i == n)
            return;

        helper(temp, nums, i + 1);
        temp.push_back(nums[i]);
        helper(temp, nums, i + 1);

        ans.push_back(temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();

        vector<int> temp;
        ans.push_back({});
        // ans.push_back();
        helper(temp, nums, 0);

        return ans;
    }
};