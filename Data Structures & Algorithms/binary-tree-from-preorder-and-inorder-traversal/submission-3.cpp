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
private:
    int pre_idx = 0, in_idx = 0;
public:
    TreeNode* buildTreeDFS(vector<int>& preorder, vector<int> inorder, int limit) {
        if (pre_idx >= preorder.size()) return nullptr;
        if (inorder[in_idx] == limit) {
            ++in_idx;
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[pre_idx++]);
        root->left = buildTreeDFS(preorder, inorder, root->val);
        // right subtree edge is parent
        root->right = buildTreeDFS(preorder, inorder, limit);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeDFS(preorder, inorder, INT_MAX);
    }
};
