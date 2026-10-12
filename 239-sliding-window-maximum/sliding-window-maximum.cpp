class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1)
            return nums;

        multiset<int> s;

        for (int i = 0; i < k; i++) {
            s.insert(nums[i]);
        }

        vector<int> ans;
        ans.push_back(*s.rbegin());

        for (int i = k; i < n; i++) {
            s.insert(nums[i]);
            s.erase(s.find(nums[i - k]));
            int maxi = *s.rbegin();
            ans.push_back(maxi);
        }

        return ans;
    }
};