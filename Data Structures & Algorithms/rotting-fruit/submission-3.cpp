class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROW = grid.size(), COL = grid[0].size();
        int numFresh = 0;
        queue<pair<int, int>> que;
        for (int r = 0; r < ROW; ++r) {
            for (int c = 0; c < COL; ++c) {
                if (grid[r][c] == 1) {
                    ++numFresh;
                }
                if (grid[r][c] == 2) {
                    que.push({r, c});
                }
            }
        }
        if (numFresh == 0) return 0;
        int minute = 0;
        vector<pair<int, int>> directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                auto [row, col] = que.front();
                que.pop();
                for (auto [dr, dc] : directions) {
                    int new_row = row + dr;
                    int new_col = col + dc;
                    if (
                        new_row >= 0 && new_row < ROW &&
                        new_col >= 0 && new_col < COL &&
                        grid[new_row][new_col] == 1
                    ) {
                        --numFresh;
                        grid[new_row][new_col] = 2;
                        que.push({new_row, new_col});
                    }
                }
            }
            ++minute;
        }
        // the last round NO need to `++minute`
        return numFresh == 0 ? minute - 1 : -1;
    }
};
