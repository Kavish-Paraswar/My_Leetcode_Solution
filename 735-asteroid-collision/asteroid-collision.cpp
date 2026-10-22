class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();

        stack<int> s;

        for (int i = 0; i < n; i++) {
            int cur = asteroids[i];

            if (cur > 0) {
                s.push(cur);
            } else {

                if (s.empty() || s.top() < 0) {
                    s.push(cur);
                    continue;
                }

                int top = s.top();

                if (abs(cur) > top) {
                    while (!s.empty() && s.top() > 0 && s.top() < abs(cur))
                        s.pop();

                    if (s.empty() || s.top() < 0)
                        s.push(cur);
                    else if (s.top() == abs(cur))
                        s.pop();
                } else if (abs(cur) == top) {
                    s.pop();
                }
            }
            // s.push(cur);
        }

        vector<int> ans;

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};