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
            int num_node = que.size();
            vector<int> level_nodes;
            while (num_node) {
                TreeNode* front = que.front();
                level_nodes.push_back(front->val);
                if (front->left) que.push(front->left);
                if (front -> right) que.push(front->right);
                que.pop();
                --num_node;
            }
            res.push_back(level_nodes);
        }
        return res;
    }
};
