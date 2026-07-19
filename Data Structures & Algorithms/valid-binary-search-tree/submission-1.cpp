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
    bool isValidBSTDFS(TreeNode* root, int left, int right) {
        if (!root) return true;
        if (root->val <= left || root->val >= right) return false;
        return (
            isValidBSTDFS(root->left, left, root->val) && 
            isValidBSTDFS(root->right, root->val, right)
        );
    }

    bool isValidBST(TreeNode* root) {
        return isValidBSTDFS(root, INT_MIN, INT_MAX);
    }
};
