class Solution {
public:
    bool canAliceWin(int n) {
        int alice = 10;
        int bob = 9;
        while (n > 0) {
            if (n < alice) {
                return false;
            }
            n -= alice;

            if (n < bob)
                return true;
            n -= bob;

            alice -= 2;
            bob -= 2;
        }

        return false;
    }
};