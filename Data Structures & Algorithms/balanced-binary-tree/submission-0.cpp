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
    int maxDepthDFS(TreeNode* root, bool& is_balanced) {
        if (!root) return 0;
        int left = maxDepthDFS(root->left, is_balanced);
        int right = maxDepthDFS(root->right, is_balanced);
        is_balanced &= (abs(left - right) <= 1);
        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        bool is_balanced = true;
        maxDepthDFS(root, is_balanced);
        return is_balanced;
    }
};
