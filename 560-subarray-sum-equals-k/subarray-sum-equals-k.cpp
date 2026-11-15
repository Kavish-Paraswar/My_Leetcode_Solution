class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        // subarr sum ,count
        unordered_map<int, int> m;
        m[0] = 1;
        int count = 0;
        int pref = 0;

        for (int i = 0; i < n; i++) {
            pref += nums[i];
            int need = pref - k;

            if (m[need] > 0)
                count += m[need];

            m[pref]++;
        }

        return count;
    }
};