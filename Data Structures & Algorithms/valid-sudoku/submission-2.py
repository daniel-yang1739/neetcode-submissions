class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows, cols, blocks = [0] * 9, [0] * 9, [0] * 9;
        for i, row in enumerate(board):
            for j, current in enumerate(row):
                if current != '.':
                    mask = (1 << int(current))
                    block_id = int(i/3)*3 + int(j/3)
                    if (
                        rows[i] & mask or
                        cols[j] & mask or
                        blocks[block_id] & mask
                    ):
                        return False
                    rows[i] |= mask
                    cols[j] |= mask
                    blocks[block_id] |= mask
        return True