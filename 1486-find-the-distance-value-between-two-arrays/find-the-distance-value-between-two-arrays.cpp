class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size(), m = arr2.size();

        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());

        int left = 0, right = 0, ans = 0;

        while (left < n) {
            while (right < m && arr2[right] < arr1[left] - d) {
                right++;
            }

            if (ans == m || abs(arr1[left] - arr2[right]) > d)
                ans++;
            left++;
        }
        return ans;
    }
};