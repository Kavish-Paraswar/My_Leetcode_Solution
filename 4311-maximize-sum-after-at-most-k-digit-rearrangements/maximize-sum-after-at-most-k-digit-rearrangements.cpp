class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int m = nums.size();
        // sort(nums.begin(), nums.end(), greater<int>());

        vector<int> op2(m, 0);
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long ans = accumulate(nums.begin(), nums.end(), 0LL);

        for (int i = 0; i < nums.size(); i++) {
            vector<int> dig(10, 0);

            int cur = nums[i];
            int n = -1;

            while (cur > 0) {
                dig[cur % 10]++;
                cur /= 10;
                n++;
            }
            long long temp = 0;

            for (int i = 9; i > 0; i--) {
                while (dig[i] > 0) {
                    temp += (pow(10, n) * i);
                    n--;
                    dig[i]--;
                }
            }

            long long gain = temp - nums[i];

            if (gain > 0 && k > 0) {
                pq.push(gain);

                if (pq.size() > k)
                    pq.pop();
            }

            op2[i] = temp;
        }

        // long long ans = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     cout << nums[i] << " " << op2[i] << endl;
        //     if (k > 0 && op2[i] > nums[i]) {
        //         ans += op2[i];
        //         k--;
        //     }

        //     else
        //         ans += nums[i];
        // }

        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};