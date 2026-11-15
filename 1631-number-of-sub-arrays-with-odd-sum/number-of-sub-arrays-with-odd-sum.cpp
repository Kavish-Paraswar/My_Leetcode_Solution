class Solution {
public:
    //  odd and even cnt
    //  odd - even = odd , so if a cur pref_sum  is odd, add all the even ending
    //  arrays ka count ,as odd - even is odd
    // similary if the pref_sum = even ,  then subarrays ending with odd will
    // also contribute ,as even - odd =  odd
    int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int pref_sum = 0, ans = 0;
        int odd = 0, even = 1;

        for (int i = 0; i < n; i++) {
            pref_sum += arr[i];
            if (pref_sum % 2 == 1) {
                ans += even;
                odd++;
            } else {
                ans += odd;
                even++;
            }
            ans = ans % mod;
        }

        return (int)ans;
    }
};
