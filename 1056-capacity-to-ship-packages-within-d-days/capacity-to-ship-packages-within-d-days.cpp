class Solution {
public:
    bool check(vector<int>& weights, int days, int mid) {
        int req_days = 1;
        int cur = 0;

        for (int& num : weights) {
            if (cur + num > mid) {
                cur = num;
                req_days++;
            } else {
                cur += num;
            }
        }

        return req_days <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int low = *max_element(weights.begin(), weights.end()),
            right = accumulate(weights.begin(), weights.end(), 0);

        while (low < right) {
            int mid = low + (right - low) / 2;

            if (check(weights, days, mid)) {
                right = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};