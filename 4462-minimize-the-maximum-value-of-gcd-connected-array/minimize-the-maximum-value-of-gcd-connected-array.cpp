class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        long long left = index, right = n - index - 1;
        long long p = value;

        if (value == 1) {
            return -1;
        }

        if (value % 2 == 0) {
            p = 2;
        } else {
            for (long long i = 3; i * i <= value; i += 2) {
                if (value % i == 0) {
                    p = i;
                    break;
                }
            }
        }

        long long left_spaces;

        if (value % 2 == 0) {
            left_spaces = value / 2 - 1;
        } else {
            left_spaces = (value - p) / 2;
        }

        if (left > left_spaces) {
            return -1;
        }

        if (right == 0) {
            return value;
        }

        if (value % 2 == 0) {
            return value + 2LL * right;
        }

        return value + p + 2LL * (right - 1);
    }
};