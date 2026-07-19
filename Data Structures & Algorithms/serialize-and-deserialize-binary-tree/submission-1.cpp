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

    string join(vector<string> preorder) {
        ostringstream oss;
        for (int i = 0; i < preorder.size(); ++i) {
            if (i != 0) oss << separator;
            oss << preorder[i];
        }
        return oss.str();
    }

    void serializeDFS(TreeNode* root, vector<string>& preorder) {
        if (!root) {
            preorder.push_back("N");
            return;
        }
        preorder.push_back(to_string(root->val));
        serializeDFS(root->left, preorder);
        serializeDFS(root->right, preorder);
    }

    vector<string> split(string data) {
        vector<string> preorder;
        stringstream ss(data);
        string temp;
        while (getline(ss, temp, separator)) {
            preorder.push_back(temp);
        }
        return preorder;
    }

    TreeNode* deserializeDFS(vector<string>& preorder, int& curr) {
        string val_str = preorder[curr];
        if (val_str == "N") return nullptr;
        TreeNode* root = new TreeNode(stoi(val_str));
        root->left = deserializeDFS(preorder, ++curr);
        root->right = deserializeDFS(preorder, ++curr);
        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> preorder;
        serializeDFS(root, preorder);
        return join(preorder);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int curr = 0;
        vector<string> preorder = split(data);
        return deserializeDFS(preorder, curr);  
    }
};