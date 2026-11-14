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
    int dfs(TreeNode* root, int level) {
        if (!root)
            return 0;

        int lefty = dfs(root->left, level + 1);
        int righty = dfs(root->right, level + 1);

        ans = max(lefty + righty, ans);
        return 1 + max(lefty, righty);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return ans;

        dfs(root, 1);
        return ans;
    }
};