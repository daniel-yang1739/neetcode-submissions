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
        maxPathSumDFS(root);
        return max_path;
    }
    int maxPathSumDFS(TreeNode* root) {
        if (!root) return 0;
        int left_max = maxPathSumDFS(root->left);
        int right_max = maxPathSumDFS(root->right);
        int path_sum = root->val;
        path_sum += (left_max) > 0 ? left_max : 0;
        path_sum += (right_max) > 0 ? right_max : 0;
        max_path = max(max_path, path_sum);
        return max(
            root->val,
            max(
                left_max + root->val,
                right_max + root->val
            )
        );
    }
};
