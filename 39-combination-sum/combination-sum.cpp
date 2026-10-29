class Solution {
public:
    set<vector<int>> s;
    int tar;

    void dfs(vector<int>& nums, int i, vector<int>& temp, int sum) {
        if (sum > tar) {
            // temp.pop_back();
            return;
        }
        if (sum == tar) {
            s.insert(temp);
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
        int sum = 0;

        dfs(nums, 0, temp, sum);

        vector<vector<int>> ans;
        while (!s.empty()) {
            vector<int> temp = *s.begin();
            ans.push_back(temp);
            s.erase(temp);
        }

        return ans;
    }
};