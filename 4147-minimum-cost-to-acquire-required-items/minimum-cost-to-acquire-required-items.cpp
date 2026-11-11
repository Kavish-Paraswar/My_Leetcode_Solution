class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        long long maxi_both = 1LL * max(need1, need2) * costBoth;
        long long each = 1LL * cost1 * need1 + 1LL * cost2 * need2;

        long long ans = min(maxi_both, each);

        if (need1 > need2) {
            long long min_cost = 1LL * cost1 * (need1 - need2);
            ans =
                min(ans, 1LL * min(cost1 + cost2, costBoth) * need2 + min_cost);
        } else {

            long long min_cost = 1LL * cost2 * (need2 - need1);
            ans =
                min(ans, 1LL * min(cost1 + cost2, costBoth) * need1 + min_cost);
        }

        return ans;
    }
};