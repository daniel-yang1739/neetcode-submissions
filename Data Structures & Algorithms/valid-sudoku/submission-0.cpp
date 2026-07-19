class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9), blocks(9);
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j <board[i].size(); ++j) {
                int current = board[i][j];
                if (current != '.') {
                    int block_id = (i/3)*3 + (j/3);
                    if (
                        rows[i].count(current) != 0 ||
                        cols[j].count(current) != 0 ||
                        blocks[block_id].count(current) != 0
                    ) { return false; }
                    rows[i].insert(current);
                    cols[j].insert(current);
                    blocks[block_id].insert(current);
                }
            }
        }
        return true;
    }
};
