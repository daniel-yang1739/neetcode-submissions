class Solution {
private:
    unordered_set<int> colSet, posDiagSet, negDiagSet;
    vector<vector<string>> res;
public:
    void backTracking(int row, int n, vector<string>& board) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (
                colSet.count(col) ||
                posDiagSet.count(row + col) ||
                negDiagSet.count(row - col)
            ) {
                continue;
            }
            colSet.insert(col);
            posDiagSet.insert(row + col);
            negDiagSet.insert(row - col);
            board[row][col] = 'Q';

            backTracking(row + 1, n, board);

            colSet.erase(col);
            posDiagSet.erase(row + col);
            negDiagSet.erase(row - col);
            board[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backTracking(0, n, board);
        return res;
    }
};
