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
    int maxi = INT_MIN;
    int dfs(TreeNode* root) {
        if (!root)
            return 0;

        int lefty = max(0, dfs(root->left));
        int righty = max(0, dfs(root->right));

        maxi = max(maxi, root->val + lefty + righty);

        return root->val + max(lefty, righty);
    }
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;

        dfs(root);

        return maxi;
    }
};