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
    int max_path = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        maxGainFrom(root);
        return max_path;
    }
    int maxGainFrom(TreeNode* root) {
        if (!root) return 0;
        int left_max = max(maxGainFrom(root->left), 0);
        int right_max = max(maxGainFrom(root->right), 0);
        max_path = max(max_path, left_max + right_max + root->val);
        return root->val + max(left_max, right_max);
    }
};
