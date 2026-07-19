class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row_size = grid.size(), col_size = grid[0].size();
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int res = 0;
        stack<pair<int, int>> stk;
        for (int i = 0; i < row_size; ++i) {
            for (int j = 0; j < col_size; ++j) {
                if (grid[i][j] == '0') continue;
                grid[i][j] = '0';
                stk.push({i, j});
                ++res;
                while (!stk.empty()) {
                    auto [row, col] = stk.top();
                    stk.pop();
                    for (auto [dr, dc] : directions) {
                        int new_row = row + dr;
                        int new_col = col + dc;
                        if (
                            new_row >= 0 && new_row < row_size &&
                            new_col >= 0 && new_col < col_size &&
                            grid[new_row][new_col] == '1'
                        ) {
                            grid[new_row][new_col] = '0';
                            stk.push({new_row, new_col});
                        }
                    }
                }
            }
        }
        return res;
    }
};
