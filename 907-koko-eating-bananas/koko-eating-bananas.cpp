class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int low = 1, high = 1e9;
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long temp = 0;

            for (int i = 0; i < n; i++) {
                temp += (piles[i] + mid - 1) / mid;
            }

            if (h >= temp) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};