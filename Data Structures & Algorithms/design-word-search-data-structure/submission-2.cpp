struct TrieNode {
    vector<TrieNode*> children;
    bool isWord;

    TrieNode(): children(26, nullptr), isWord(false) {};
};

class WordDictionary {
private:
    TrieNode* root = new TrieNode();
public:
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children[c - 'a']) {
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        return dfs(root, 0, word);
    }

    bool dfs(TrieNode* root, int idx, const string& word) {
        if (idx == word.size()) {
            return root->isWord;
        }

        char c = word[idx];
        if (c == '.') {
            for (int i = 0; i < 26; ++i) {
                if (
                    root->children[i] && 
                    dfs(root->children[i], idx + 1, word)
                ) {
                    return true;
                }
            }
            return false;
        }

        if (!root->children[c - 'a']) {
            return false;
        }
        return dfs(root->children[c - 'a'], idx + 1, word);
    }
};
