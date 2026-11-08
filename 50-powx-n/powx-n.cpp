class Solution {
public:
    double helper(double x, long long n) {
        if (n == 0)
            return 1.0;

        double half = helper(x, n / 2);

        if (n % 2 == 0)
            return half * half;

        return x * half * half;
    }
    double myPow(double x, int n) {
        if (x == 1)
            return x;
        if (x == -1) {
            if (n % 2 == 0)
                return 1;
            return -1;
        }

        long long pow = n;

        if (pow < 0) {
            return 1.0 / helper(x, -pow);
        }

        return helper(x, pow);
    }
};