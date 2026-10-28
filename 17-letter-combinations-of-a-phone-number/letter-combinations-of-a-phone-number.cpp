class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> ans = {""};
        vector<string> check = {{"abc"}, {"def"},  {"ghi"}, {"jkl"},
                                {"mno"}, {"pqrs"}, {"tuv"}, {"wxyz"}};

        for (int i = 0; i < n; i++) {
            char cur = digits[i];
            string add = check[cur - '2'];
            vector<string> next;

            for (char& c : add) {
                for (auto& a : ans) {
                    string temp = a;
                    temp += c;
                    next.push_back(temp);
                }
            }
            ans = next;
        }

        return ans;
    }
};