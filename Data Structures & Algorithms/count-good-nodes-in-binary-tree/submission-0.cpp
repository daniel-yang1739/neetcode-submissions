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
    int goodNodesDFS(TreeNode* root, int max_value) {
        if (!root) return 0;
        int curr = root->val >= max_value ? 1 : 0;
        max_value = max(max_value, root->val);
        int left = goodNodesDFS(root->left, max_value);
        int right = goodNodesDFS(root->right, max_value);
        return left + right + curr;
    }

    int goodNodes(TreeNode* root) {
        return goodNodesDFS(root, root->val);
    }
};
