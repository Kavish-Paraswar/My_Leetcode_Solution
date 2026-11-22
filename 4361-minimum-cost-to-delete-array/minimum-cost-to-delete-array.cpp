class Solution {
public:
    long long minCost(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 1; i < nums.size() - 1; i++)
            pq.push(nums[i]);
        long long ans = nums[0] + nums.back();
        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            
            int b = pq.top();
            pq.pop();
            int sum = a + b;
            if (sum < 0)
                ans += sum;
            else
                break;
        }
        return ans;
    }
};