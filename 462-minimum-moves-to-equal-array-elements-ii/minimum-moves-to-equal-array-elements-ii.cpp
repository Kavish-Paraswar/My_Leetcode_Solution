class Solution {
public:
    long long cost(vector<int>& nums, long long target) {
        long long ans = 0;

        for (int& val : nums) {
            ans += abs((long long)val - target);
        }

        return ans;
    }
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        // int ans = ;

        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (cost(nums, mid) <= cost(nums, mid + 1)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return (int)cost(nums, left);
    }
};