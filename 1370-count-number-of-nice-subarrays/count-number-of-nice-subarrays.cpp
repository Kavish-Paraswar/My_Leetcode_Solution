class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        // vector<int> next_odd(n, n);
        // int odd = n;

        // for (int i = n - 1; i >= 0; i--) {
        //     next_odd[i] = odd;
        //     if (nums[i] % 2 == 1)
        //         odd = i;
        // }

        int left = 0, ans = 0;
        int cnt = 0;

        int temp = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] % 2 == 1) {
                temp = 0;
                cnt++;
            }

            while (cnt >= k) {
                if (nums[left] % 2 == 1)
                    cnt--;
                left++;
                temp++;
            }
            ans += temp;
        }

        return ans;
    }
};