class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROW = grid.size(), COL = grid[0].size();
        queue<pair<int, int>> que;
        for (int r = 0; r < ROW; ++r) {
            for (int c = 0; c < COL; ++c) {
                if (grid[r][c] == 0) {
                    que.push({r, c});
                }
            }
        }
        int length = 1;
        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                auto [row, col] = que.front();
                que.pop();
                for (auto& [dr, dc] : directions) {
                    int new_row = row + dr;
                    int new_col = col + dc;
                    if (
                        new_row >= 0 && new_row < ROW &&
                        new_col >= 0 && new_col < COL &&
                        grid[new_row][new_col] == INT_MAX
                    ) {
                        grid[new_row][new_col] = length;
                        que.push({new_row, new_col});
                    }
                }
            }
            ++length;
        }
    }
};
