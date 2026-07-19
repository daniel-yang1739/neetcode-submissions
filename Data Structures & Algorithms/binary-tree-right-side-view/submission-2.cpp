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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return vector<int>();
        vector<int> res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int level_size = que.size();
            for (int i = level_size; i > 0; --i) {
                TreeNode* front = que.front();
                if (i == level_size) res.push_back(front->val);
                if (front->right) que.push(front->right);  // right first
                if (front->left) que.push(front->left);
                que.pop();
            }
        }
        return res;
    }
};
