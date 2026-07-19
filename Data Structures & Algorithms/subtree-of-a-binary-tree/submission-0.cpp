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
    bool isSameTree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (!root || !subRoot) return false;
        bool left = isSameTree(root->left, subRoot->left);
        bool right = isSameTree(root->right, subRoot->right);
        return left && right && (root->val == subRoot->val);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<TreeNode*> stack;
        stack.push_back(root);
        while (!stack.empty()) {
            TreeNode* currRoot = stack.back();
            stack.pop_back();
            if (currRoot->val == subRoot->val) {
                if (isSameTree(currRoot, subRoot)) {
                    return true;
                }
            }
            if (currRoot->left) stack.push_back(currRoot->left);
            if (currRoot->right) stack.push_back(currRoot->right);
        }
        return false;
    }
};
