class Solution {
private:
    unordered_set<int> colSet, posDiagSet, negDiagSet;
    vector<vector<string>> res;
public:
    vector<string> getChessPattern(vector<int>& queenCols) {
        int size = queenCols.size();
        vector<string> pattern;
        for (int r = 0; r < size; ++r) {
            string rowPattern(size, '.');
            rowPattern[queenCols[r]] = 'Q';
            pattern.push_back(rowPattern);
        }
        return pattern;
    }

    void backTracking(int row, int n, vector<int>& queenCols) {
        if (row == n) {
            vector<string> pattern = getChessPattern(queenCols);
            res.push_back(pattern);
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

            queenCols[row] = col;
            backTracking(row + 1, n, queenCols);

            colSet.erase(col);
            posDiagSet.erase(row + col);
            negDiagSet.erase(row - col);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int> queenCols(n);
        backTracking(0, n, queenCols);
        return res;
    }
};
