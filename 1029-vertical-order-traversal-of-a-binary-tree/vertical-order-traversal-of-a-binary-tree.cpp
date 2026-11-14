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
    map<int, vector<pair<int, int>>> m;

    void helper(int row, int col, TreeNode* node) {
        if (!node)
            return;

        helper(row + 1, col - 1, node->left);
        m[col].push_back({row, node->val});
        helper(row + 1, col + 1, node->right);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        m.clear();
        if (!root) {
            return {{}};
        }

        helper(0, 0, root);
        vector<vector<int>> ans;
        vector<int> temp;

        for (auto& it : m) {
            sort(it.second.begin(), it.second.end());

            for (auto& cur : it.second) {
                temp.push_back({cur.second});
            }
            ans.push_back(temp);
            temp.clear();
        }

        return ans;
    }
};