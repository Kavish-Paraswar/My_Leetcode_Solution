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

        int lefty = dfs(root->left);
        int righty = dfs(root->right);

        // maxi = max(root->val, maxi);
        maxi = max(maxi, root->val + max(0, lefty) + max(0, righty));

        return root->val + max({0, lefty, righty});
    }
    int maxPathSum(TreeNode* root) {
        int sum = dfs(root);
        return maxi;
    }
};