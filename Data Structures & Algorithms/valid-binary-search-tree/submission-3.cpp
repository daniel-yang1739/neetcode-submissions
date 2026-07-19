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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        queue<tuple<TreeNode*, int, int>> que;
        que.push(make_tuple(root, INT_MIN, INT_MAX));
        while (!que.empty()) {
            auto [front, left, right] = que.front();
            if (front->val <= left || front->val >= right) {
                return false;
            }
            if (front->left) {
                que.push(make_tuple(front->left, left, front->val));
            }
            if (front->right) {
                que.push(make_tuple(front->right, front->val, right));
            }
            que.pop();
        }
        return true;
    }
};
