/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        long long global_max = 0;

        while (!q.empty()) {
            int sz = q.size();
            long long mini = INT_MAX, maxi = INT_MIN;
            int val = q.front().second;

            for (int i = 0; i < sz; i++) {
                auto [node, index] = q.front();
                index = index - val;
                mini = min(mini, index);
                maxi = max(maxi, index);
                q.pop();

                if (node->left) {
                    q.push({node->left, 2 * index});
                }
                if (node->right) {
                    q.push({node->right, 2 * index + 1});
                }
            }

            if (maxi != INT_MIN && mini != INT_MAX)
                global_max = max(global_max, maxi - mini);
        }

        return (int)global_max + 1;
    }
};