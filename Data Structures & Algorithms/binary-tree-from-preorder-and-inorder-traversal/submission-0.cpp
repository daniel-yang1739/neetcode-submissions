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
    TreeNode* buildTreeDFS(
        vector<int>& preorder, 
        unordered_map<int, int>& inorder_index, 
        vector<bool>& seen, 
        int& r_index
    ) {
        int root_val = preorder[r_index];
        TreeNode* root = new TreeNode(root_val);
        int idx = inorder_index[root_val];
        seen[idx] = true;
        if (idx - 1 >= 0 && !seen[idx - 1]) {
            ++r_index;
            root->left = buildTreeDFS(
                preorder, inorder_index, seen, r_index);
        }
        if (idx + 1 < preorder.size() && !seen[idx + 1]) {
            ++r_index;
            root->right = buildTreeDFS(
                preorder, inorder_index, seen, r_index);
        }
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorder_index;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_index[inorder[i]] = i;
        }
        int index = 0;
        vector<bool> seen(inorder.size(), false);
        return buildTreeDFS(preorder, inorder_index, seen, index);
    }
};
