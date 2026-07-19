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

class Codec {
private:
    char separator = ',';

    string join(vector<string> level_order) {
        ostringstream oss;
        for (int i = 0; i < level_order.size(); ++i) {
            if (i != 0) oss << separator;
            oss << level_order[i];
        }
        return oss.str();
    }

    void serializeDFS(TreeNode* root, vector<string>& level_order) {
        if (!root) {
            level_order.push_back("N");
            return;
        }
        level_order.push_back(to_string(root->val));
        serializeDFS(root->left, level_order);
        serializeDFS(root->right, level_order);
    }

    vector<string> split(string data) {
        vector<string> level_order;
        stringstream ss(data);
        string temp;
        while (getline(ss, temp, separator)) {
            level_order.push_back(temp);
        }
        return level_order;
    }

    TreeNode* deserializeDFS(vector<string>& level_order, int& curr) {
        string val_str = level_order[curr];
        if (val_str == "N") return nullptr;
        TreeNode* root = new TreeNode(stoi(val_str));
        root->left = deserializeDFS(level_order, ++curr);
        root->right = deserializeDFS(level_order, ++curr);
        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> level_order;
        serializeDFS(root, level_order);
        return join(level_order);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int curr = 0;
        vector<string> level_order = split(data);
        return deserializeDFS(level_order, curr);  
    }
};