class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> rows(9, 0), cols(9, 0), blocks(9, 0);
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j <board[i].size(); ++j) {
                if (board[i][j] != '.') {
                    int mask = (1 << (board[i][j] - '1'));
                    int block_id = (i/3)*3 + (j/3);
                    if (
                        rows[i] & mask ||
                        cols[j] & mask ||
                        blocks[block_id] & mask
                    ) { return false; }
                    rows[i] |= mask;
                    cols[j] |= mask;
                    blocks[block_id] |= mask;
                }
            }
        }
        return true;
    }
};
