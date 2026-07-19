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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<pair<int, TreeNode*>> que;
        que.push({0, root});
        while (!que.empty()) {
            pair<int, TreeNode*> front = que.front();
            que.pop();
            if (res.size() <= front.first) {
                res.push_back({});
            }
            res[front.first].push_back(front.second->val);
            if (front.second->left) {
                que.push({front.first + 1, front.second->left});
            }
            if (front.second->right) {
                que.push({front.first + 1, front.second->right});
            }
        }
        return res;
    }
};
