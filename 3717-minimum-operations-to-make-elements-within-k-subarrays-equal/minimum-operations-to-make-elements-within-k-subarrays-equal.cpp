class Solution {
public:
    // step 1 - cost for all subarry of size x
    // step 2 - use 2 maps to cal lower and greater values with remove and
    // deleting them step 3 -  cal cost of that sub of x =
    //  size of low * median - Sum(value in map low) + sum(value in map(high)
    //  -size of of high * median
    // step 4 - store all values and do simple 2d , dp to choose exactly k
    // subarrays step 5 - dp[n][k] , with all value = 0
    // step 6 = dp[i][j] =
    // max(dp[i - x][j - 1] + cost[i -x] ,dp[i - 1][j]); return dp[n - 1][ k -
    // 1]

    map<int, int> low, high;
    long long sum_low = 0, sum_high = 0;
    int low_size = 0, high_size = 0;

    void add(int num) {
        low[num]++;
        low_size++;
        sum_low += num;

        int largest = low.rbegin()->first;

        low[largest]--;
        low_size--;
        sum_low -= largest;

        if (low[largest] == 0)
            low.erase(largest);

        high[largest]++;
        high_size++;
        sum_high += largest;

        if (low_size < high_size) {
            int smallest = high.begin()->first;

            high[smallest]--;
            high_size--;
            sum_high -= smallest;

            if (high[smallest] == 0)
                high.erase(smallest);

            low[smallest]++;
            low_size++;
            sum_low += smallest;
        }
    }

    void remove(int num) {
        auto it = low.find(num);
        if (it != low.end()) {
            low[num]--;
            low_size--;
            sum_low -= num;
            if (low[num] == 0) {
                low.erase(num);
            }
        }

        else {
            high[num]--;
            high_size--;
            sum_high -= num;
            
            if (high[num] == 0) {
                high.erase(num);
            }
        }

        if (low_size < high_size) {
            int smallest = high.begin()->first;

            high[smallest]--;
            high_size--;
            sum_high -= smallest;

            if (high[smallest] == 0)
                high.erase(smallest);

            low[smallest]++;
            low_size++;
            sum_low += smallest;
        }

        if (low_size > high_size + 1) {
            int largest = low.rbegin()->first;

            low[largest]--;
            low_size--;
            sum_low -= largest;

            if (low[largest] == 0)
                low.erase(largest);

            high[largest]++;
            high_size++;
            sum_high += largest;
        }
    }

    long long helper() {
        long long median = low.rbegin()->first;

        long long cost =
            median * low_size - sum_low + sum_high - (median * high_size);
        return cost;
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<long long> cost(n, 0);

        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }
        cost[0] = helper();

        for (int i = x; i < n; i++) {
            add(nums[i]);
            remove(nums[i - x]);
            cost[i - x + 1] = helper();
        }

        vector<vector<long long>> dp(n + 1,
                                     vector<long long>(k + 1, LLONG_MAX / 4));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];

                if (i >= j * x) {
                    dp[i][j] = min(dp[i - x][j - 1] + cost[i - x], dp[i][j]);
                }
            }
        }

        return dp[n][k];
    }
};