class Solution {
private:
    int R, C;
    vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
    vector<vector<int>> memoization;

public:
    int dfs(
        int r, int c, int prevVal,
        vector<vector<int>>& matrix
    ) {
        if (
            r < 0 || r >= R || c < 0 || c >= C ||
            matrix[r][c] <= prevVal
        ) {
            return 0;
        }

        if (memoization[r][c] != -1) {
            return memoization[r][c];
        }

        int res = 1;
        for (const auto& [dr, dc] : directions) {
            int newRow = r + dr, newCol = c + dc;
            res = max(res, 1 + dfs(newRow, newCol, matrix[r][c], matrix));
        }
        return memoization[r][c] = res;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        R = matrix.size(), C = matrix[0].size();
        memoization = vector<vector<int>>(R, vector<int>(C, -1));
        int LIP = 0;
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) { 
                LIP = max(LIP, dfs(r, c, INT_MIN, matrix));
            }
        }
        return LIP;
    }
};
