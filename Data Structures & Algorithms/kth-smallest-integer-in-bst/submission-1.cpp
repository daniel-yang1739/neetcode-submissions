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
    void kthSmallestDFS(TreeNode* root, pair<int, int>& tmp) {
        if (!root) return;
        kthSmallestDFS(root->left, tmp);
        --tmp.first;
        if (tmp.first == 0) {
            tmp.second = root->val;
            return;
        }
        kthSmallestDFS(root->right, tmp);
    }

    int kthSmallest(TreeNode* root, int k) {
        pair<int, int> tmp = {k, -1};  // count, res
        kthSmallestDFS(root, tmp);
        return tmp.second;
    }
};
