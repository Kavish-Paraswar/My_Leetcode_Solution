/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*, TreeNode*> parent;
    vector<int> ans;
    set<TreeNode*> vis;

    void parent_bfs(TreeNode* root) {
        if (!root)
            return;

        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, root});

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {

                auto [child_node, parent_node] = q.front();
                q.pop();

                if (child_node->left) {
                    q.push({child_node->left, child_node});
                    parent[child_node->left] = child_node;
                }

                if (child_node->right) {
                    q.push({child_node->right, child_node});
                    parent[child_node->right] = child_node;
                }
            }
        }
    }

    void dfs(TreeNode* target, int k) {

        stack<pair<TreeNode*, int>> s;
        s.push({target, 0});
        vis.insert(target);

        while (!s.empty()) {
            auto [cur_node, cur_k] = s.top();
            s.pop();
            if (cur_k == k) {
                ans.push_back(cur_node->val);
                continue;
            }

            if (cur_node->right && !vis.count(cur_node->right)) {
                s.push({cur_node->right, cur_k + 1});
                vis.insert(cur_node->right);
            }
            if (cur_node->left && !vis.count(cur_node->left)) {
                s.push({cur_node->left, cur_k + 1});
                vis.insert(cur_node->left);
            }

            if (parent.find(cur_node) != parent.end() &&
                !vis.count(parent[cur_node])) {
                s.push({parent[cur_node], cur_k + 1});
                vis.insert(parent[cur_node]);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root)
            return {};

        parent.clear();
        ans.clear();
        vis.clear();

        parent_bfs(root);
        dfs(target, k);

        return ans;
    }
};