class Solution {
public:
    int tar;
    vector<vector<int>> ans;

    void dfs(vector<int>& nums, int i, vector<int>& temp, int sum) {
        if (sum > tar) {
            return;
        }
        if (sum == tar) {
            ans.push_back(temp);
            return;
        }

        for (int k = i; k < nums.size(); k++) {
            if (nums[k] + sum <= tar) {
                temp.push_back(nums[k]);
                sum += nums[k];
                dfs(nums, k, temp, sum);
                temp.pop_back();
                sum -= nums[k];
            }
        }

        // dfs(nums, i + 1, temp, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        tar = target;
        vector<int> temp;

        dfs(nums, 0, temp, 0);
        return ans;
    }
};