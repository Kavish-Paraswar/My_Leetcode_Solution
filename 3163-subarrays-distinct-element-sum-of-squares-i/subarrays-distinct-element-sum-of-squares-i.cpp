class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        set<int> s;
        int ans = n;

        for (int i = 0; i < n - 1; i++) {
            s.insert(nums[i]);
            for (int j = i + 1; j < n; j++) {
                s.insert(nums[j]);
                int temp = s.size();
                ans += (temp * temp);
            }
            s.clear();
        }

        return ans;
    }
};