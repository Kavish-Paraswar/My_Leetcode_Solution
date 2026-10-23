
class Solution {
public:
    int helper(int start, int end) {
        int range = end - start;
        int digits = 0, place = 1;

        while (place <= range / 10) {
            digits++;
            place *= 10;
        }

        if (digits == 0) {
            return 0;
        }

        return digits * (place / 10);
    }

    int countDigitOne(int n) {
        if (n == 0) {
            return 0;
        }

        int place = 1, digits = 0;

        while (n / place >= 10) {
            place *= 10;
            digits++;
        }

        int first = n / place, rem = n % place, ans = first * helper(0, place);

        if (first == 1) {
            ans += rem + 1;
        } else {
            ans += place;
        }

        ans += countDigitOne(rem);
        return ans;
    }
};
