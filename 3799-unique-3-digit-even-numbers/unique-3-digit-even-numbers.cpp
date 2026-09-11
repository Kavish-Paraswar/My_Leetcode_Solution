class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int cnt[10] = {};

        for (int x : digits)
            cnt[x]++;

        int ans = 0;

        for (int k = 0; k <= 8; k += 2) {
            if (cnt[k] == 0)
                continue;

            cnt[k]--;

            int first = 0;

            for (int i = 1; i <= 9; i++) {
                if (cnt[i] > 0)
                    first++;
            }

            for (int i = 1; i <= 9; i++) {
                if (cnt[i] == 0)
                    continue;

                cnt[i]--;

                int second = 0;
                for (int j = 0; j <= 9; j++) {
                    if (cnt[j] > 0)
                        second++;
                }

                ans += second;
                cnt[i]++;
            }

            cnt[k]++;
        }

        return ans;
    }
};