class Solution {
public:
    int calculateScore(int a, int b) {
        int s1 = 0, s2 = 0;

        while (a > 0) {
            s1 += (a & 1);
            a = a >> 1;
        }

        while (b > 0) {
            s2 += (b & 1);
            b = b >> 1;
        }
        cout << s1 << "  " << s2;
        if (s1 >= s2)
            return s1 * s2;
        return s2 / s1;
    }
};