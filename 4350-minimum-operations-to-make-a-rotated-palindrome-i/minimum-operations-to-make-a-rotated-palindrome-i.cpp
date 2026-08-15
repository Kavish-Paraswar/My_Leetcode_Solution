class Solution {
public:
    int minOperations(string s) {
        int n = s.length(), maxi = 0, use, mini = INT_MAX;

        int ptr = 0;

        while (ptr < n) {
            use = ptr;
            maxi = 0;

            // we can just brute force this right??
            // like mujhe esa lagta hai ki as n = 2k hai , so o(n2) works so
            // lets permute it

            while (maxi < n / 2) {
                int incr = (s[maxi] - s[n - 1 - maxi] + 26) % 26;
                int lefty = (s[n - 1 - maxi] - s[maxi] + 26) % 26;
                use += min(incr, lefty);
                maxi++;
            }
            mini = min(mini, use);
            s = s.substr(1) + s[0];
            ptr++;
        }

        return mini;
    }
};