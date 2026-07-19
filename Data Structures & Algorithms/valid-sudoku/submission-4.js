class Solution {
    /**
     * @param {character[][]} board
     * @return {boolean}
     */
    isValidSudoku(board) {
        const rows = new Array(9).fill(0);
        const cols = [...rows];
        const blocks = [...rows];
        for (let i = 0; i < board.length; ++i) {
            for (let j = 0; j < board[i].length; ++j) {
                if (board[i][j] !== '.') {
                    const mask = (1 << parseInt(board[i][j]));
                    const block_id = Math.floor(i/3) *3 + Math.floor(j/3);
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
}
