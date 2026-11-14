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
    int ans = 0;
    int dfs(TreeNode* root) {
        if (!root)
            return 0;

        int lefty = dfs(root->left);
        int righty = dfs(root->right);

        ans = max(lefty + righty, ans);
        return 1 + max(lefty, righty);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return ans;

        dfs(root);
        return ans;
    }
};