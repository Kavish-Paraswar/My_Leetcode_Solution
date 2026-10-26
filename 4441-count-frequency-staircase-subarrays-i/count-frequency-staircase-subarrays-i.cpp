class Solution {
public:
    bool helper(int start, int end, vector<int>& nums, map<int, int>& freq) {
        // map<int, int> freq;
        set<int> s;

        // for (int i = start; i <= end; i++) {
        //     freq[nums[i]]++;
        // }
        int k = 1;
        for (int i = start; i <= end; i++) {
            if (s.find(nums[i]) == s.end()) {
                if (freq[nums[i]] != k)
                    return false;
                k++;
                s.insert(nums[i]);
            }
        }

        return true;
    }
    int countStaircase(vector<int>& nums) {
        int ans = 0;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            map<int, int> freq;
            for (int j = i; j < n; j++) {
                freq[nums[j]]++;

                int k = freq.size();
                int len = j - i + 1;

                if (1LL * k * (k + 1) / 2 != len)
                    continue;

                if (helper(i, j, nums, freq))
                    ans++;
            }
        }

        return ans;
    }
};