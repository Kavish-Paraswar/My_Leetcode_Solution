class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int> wind;
        int ans = 1;

        int lefty = 0;
        for (int right = 0; right < n; right++) {
            wind.insert(nums[right]);

            int maxi = *wind.rbegin(), mini = *wind.begin();

            if (abs(maxi - mini) <= limit)
                ans = max(ans, right - lefty + 1);

            while (lefty < right && abs(maxi - mini) > limit) {
                wind.erase(wind.find(nums[lefty]));
                lefty++;
                maxi = *wind.rbegin(), mini = *wind.begin();
            }
        }

        return ans;
    }
};