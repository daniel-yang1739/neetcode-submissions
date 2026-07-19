class Solution {
public:
    int R, C;
    vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    bool back_tracking(
        int row, int col, 
        int i, string& word,
        vector<vector<char>>& board,
        vector<vector<bool>>& visited
    ) {
        if (board[row][col] != word[i]) {
            return false;
        }
        if (i == word.size() - 1) {
            return true;
        }
        visited[row][col] = true;
        bool hasWord = false;
        for (const auto& [dr, dc] : directions) {
            int new_row = row + dr;
            int new_col = col + dc;
            if (
                new_row >= 0 && new_row < R &&
                new_col >= 0 && new_col < C &&
                !visited[new_row][new_col] &&
                back_tracking(
                    new_row, new_col, i + 1, word, board, visited)
            ) {
                hasWord = true;
                break;
            }
        }
        visited[row][col] = false;
        return hasWord;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        R = board.size(), C = board[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (
                    board[r][c] == word[0] && 
                    back_tracking(r, c, 0, word, board, visited)
                ) {
                    return true;
                }
            }
        }
        return false;
    }
};
