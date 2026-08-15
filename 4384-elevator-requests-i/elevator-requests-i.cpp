class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int ans = 0, cur = 0;
        int size = requests.size();

        for (int i = 0; i < size; i++) {
            int temp = ans - requests[i];
            cur += abs(temp);
            ans = requests[i];
        }

        return cur;
    }
};