class Solution {
public:
    int maxScore(vector<int>& nums) {
        long long cur_sum = 0;
        int count = 0;
        priority_queue<int> pq;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] <= 0)
                pq.push(nums[i]);
            else {
                cur_sum += nums[i];
                count++;
            }
        }
        cout << cur_sum << " " << count << endl;

        while (!pq.empty()) {
            int val = pq.top();
            cur_sum += val;
            if (cur_sum <= 0)
                break;
            cout << val << " ";
            count++;
            pq.pop();
        }

        return count;
    }
};