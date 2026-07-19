struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isWord;
    
    TrieNode(): isWord(false) {};
};

class Trie {
public:
    TrieNode* root = new TrieNode();
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children.count(c)) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isWord = true;
    }
};

class Solution {
private:
    int R, C;
    unordered_set<string> res;
    vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
public:
    vector<string> findWords(
        vector<vector<char>>& board, vector<string>& words
    ) {
        // Trie Construction
        Trie trie = Trie();
        for (string word : words) {
            trie.addWord(word);
        }
       
        R = board.size(), C = board[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        string currStr = "";
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                char letter = board[r][c];
                if (trie.root->children.count(letter)) {
                    currStr.push_back(letter);
                    dfs(
                        r, c, trie.root->children[letter], 
                        currStr, board, visited
                    );
                    currStr.pop_back();
                }
            }
        }
        return vector<string>(res.begin(), res.end());
    }

    void dfs(
        int row, int col, 
        TrieNode* root, string& currStr,
        vector<vector<char>>& board, 
        vector<vector<bool>>& visited
    ) {
        if (root->isWord) {
            res.insert(currStr);
        }

        visited[row][col] = true;
        for (const auto& [dr, dc] : directions) {
            int new_row = row + dr;
            int new_col = col + dc;
            if (
                new_row >= 0 && new_row < R &&
                new_col >= 0 && new_col < C &&
                !visited[new_row][new_col]
            ) {
                char letter = board[new_row][new_col];
                if (!root->children.count(letter)) {
                    continue;
                }
                currStr.push_back(letter);
                dfs(
                    new_row, new_col, root->children[letter],
                    currStr, board, visited
                );
                currStr.pop_back();
            } 
        }
        visited[row][col] = false;
    }
};
