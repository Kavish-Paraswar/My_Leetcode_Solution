class Solution {
public:
    set<vector<int>> s;
    int n;

    void helper(vector<int>& temp, vector<int>& nums, int i) {
        if (i == n) {
            s.insert(temp);
            return;
        }

        temp.push_back(nums[i]);
        helper(temp, nums, i + 1);

        temp.pop_back();
        helper(temp, nums, i + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();

        vector<int> temp;
        sort(nums.begin(), nums.end());
        // ans.push_back({});
        // ans.push_back();
        helper(temp, nums, 0);
        vector<vector<int>> ans;

        while (!s.empty()) {
            temp = *s.begin();
            s.erase(temp);
            ans.push_back(temp);
        }

        return ans;
    }
};