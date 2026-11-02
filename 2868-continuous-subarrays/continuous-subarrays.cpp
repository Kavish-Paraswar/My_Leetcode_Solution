class Solution {
public:
    map<int, int> m;
    long long helper() {
        int mini = m.begin()->first;
        int maxi = m.rbegin()->first;

        return maxi - mini;
    }

    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();

        int left = 0, right = 0;
        long long ans = 0;

        for (int right = 0; right < n; right++) {
            m[nums[right]]++;

            long long cost = helper();

            while (cost > 2) {
                m[nums[left]]--;
                if (m[nums[left]] == 0) {
                    m.erase(nums[left]);
                }
                left++;
                cost = helper();
            }
            ans += (right - left + 1);
        }

        return ans;
    }
};