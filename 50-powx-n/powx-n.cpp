class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1)
            return x;
        if (x == -1) {
            if (n % 2 == 0)
                return 1;
            return -1;
        }

        long long pow = n;
        double ans = 1.0;
        double base = x;

        if (pow < 0) {
            pow = -pow;
        }

        while (pow > 0) {
            if (pow % 2 == 1) {
                ans *= base;
            }

            base *= base;
            pow /= 2;
        }

        if (n < 0)
            return 1.0L / ans;

        return ans;
    }
};