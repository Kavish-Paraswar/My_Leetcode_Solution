class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if ((num * 9) < sum) {
            return "";
        }
        // int n = nums.size();
        string ans;

        while (sum >= 9 && num > 0) {
            ans.push_back('9');
            sum -= 9;
            num--;
        }

        if (sum > 0 && num > 0) {
            ans.push_back('0' + sum);
            num--;
            sum = 0;
        }
        while (num > 0 && sum == 0) {
            ans.push_back('0');
            num--;
        }

        return ans;
    }
};