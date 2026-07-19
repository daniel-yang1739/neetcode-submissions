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
    int r_index = 0;
    unordered_map<int, int> inorder_indices;
public:
    TreeNode* buildTreeDFS(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr;
        int root_val = preorder[r_index++];
        TreeNode* root = new TreeNode(root_val);
        int mid = inorder_indices[root_val];
        root->left = buildTreeDFS(preorder, left, mid - 1);
        root->right = buildTreeDFS(preorder, mid + 1, right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_indices[inorder[i]] = i;
        }
        return buildTreeDFS(preorder, 0, inorder.size() - 1);
    }
};
