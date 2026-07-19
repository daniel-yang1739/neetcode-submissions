class Solution {
private:
    int ROW, COL;
    vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
public:
    void checkConnectedDFS(
        int row, int col,
        vector<vector<char>>& board,
        vector<vector<bool>>& can_to_bound
    ) {
        if (board[row][col] == 'X') return;
        can_to_bound[row][col] = true;
        for (auto& [dr, dc] : directions) {
            int new_row = row + dr;
            int new_col = col + dc;
            if (
                new_row >= 0 && new_row < ROW &&
                new_col >= 0 && new_col < COL &&
                board[new_row][new_col] == 'O' &&
                !can_to_bound[new_row][new_col]
            ) {
                checkConnectedDFS(
                    new_row, new_col, board, can_to_bound
                );
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        ROW = board.size(), COL = board[0].size();
        vector<vector<bool>> can_to_bound(ROW, vector<bool>(COL, false));
        for (int r = 0; r < ROW; ++r) {
            checkConnectedDFS(r, 0, board, can_to_bound);
            checkConnectedDFS(r, COL -1, board, can_to_bound);
        }
        for (int c = 0; c < COL; ++c) {
            checkConnectedDFS(0, c, board, can_to_bound);
            checkConnectedDFS(ROW - 1, c, board, can_to_bound);
        }
        for (int r = 0; r < ROW; ++r) {
            for (int c = 0; c < COL; ++c) {
                if (board[r][c] == 'O' && !can_to_bound[r][c]) {
                    board[r][c] = 'X';
                }
            }
        }
    }
};
