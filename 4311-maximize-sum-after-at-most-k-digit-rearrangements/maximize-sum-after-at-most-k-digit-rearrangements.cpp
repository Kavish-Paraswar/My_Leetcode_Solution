
class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int m = nums.size();

        priority_queue<pair<long long, long long>,
                       vector<pair<long long, long long>>,
                       function<bool(pair<long long, long long>,
                                     pair<long long, long long>)>>
            pq([](auto a, auto b) {
                return a.second - a.first < b.second - b.first;
            });

        for (int i = 0; i < m; i++) {
            vector<int> dig(10, 0);

            int cur = nums[i];

            while (cur > 0) {
                dig[cur % 10]++;
                cur /= 10;
            }

            long long temp = 0;

            for (int j = 9; j >= 0; j--) {
                while (dig[j] > 0) {
                    temp = temp * 10 + j;
                    dig[j]--;
                }
            }

            pq.push({nums[i], temp});
        }

        long long ans = accumulate(nums.begin(), nums.end(), 0LL);

        while (k > 0 && !pq.empty()) {
            auto [original, rearranged] = pq.top();
            pq.pop();

            ans += max(original, rearranged) - original;
            k--;
        }

        return ans;
    }
};
