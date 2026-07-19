/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> level_nodes;
            for (int i = 0; i < size; ++i) {
                TreeNode* front = que.front();
                level_nodes.push_back(front->val);
                que.pop();
                if (front->left) que.push(front->left);
                if (front -> right) que.push(front->right);
            }
            res.push_back(level_nodes);
        }
        return res;
    }
};
