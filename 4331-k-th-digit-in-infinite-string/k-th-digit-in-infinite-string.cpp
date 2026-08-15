class Solution {
public:
    using ll = long long;
    int kthDigit(long long k) {
        ll ans = 2, cur = 1, maxi = 0, temp = 0, mini = INT_MAX;

        // less than 10 , k willl be just k as that operation will just result
        // in % 10 ,so
        if (k <= 9)
            return k;

        k -= 9;
        while (ans > 0) {
            maxi = 9 * 10 * (cur * ans);

            if (k <= maxi) {
                break;
            }

            k -= maxi;
            cur *= 10;
            ans++;
        }

        temp = k - 1;
        maxi = cur + temp / (10 * ans);
        temp = temp % (10 * ans);

        mini = temp / ans;

        if (maxi % 2 != 0) {
            mini = 9 - mini;
        }

        maxi = maxi * 10 + mini;
        temp = temp % ans;
        mini = ans - temp - 1;

        while (mini > 0) {
            maxi /= 10;
            mini--;
        }

        return maxi % 10;
    }
};