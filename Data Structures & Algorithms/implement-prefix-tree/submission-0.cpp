struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
};

class PrefixTree {
private:
    TrieNode* root = new TrieNode();
public:
    void insert(string word) {
        TrieNode* currNode = root;
        for (char c : word) {
            if (!currNode->children.count(c)) {
                currNode->children[c] = new TrieNode();
            }
            currNode = currNode->children[c];
        }
        currNode->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* currNode = root;
        for (char c : word) {
            if (!currNode->children.count(c)) {
                return false;
            }
            currNode = currNode->children[c];
        }
        return currNode->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* currNode = root;
        for (char c : prefix) {
            if (!currNode->children.count(c)) {
                return false;
            }
            currNode = currNode->children[c];
        }
        return true;
    }
};
