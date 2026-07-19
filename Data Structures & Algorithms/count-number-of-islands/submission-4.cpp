class Solution {
private:
    int ROW, COL;   
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    void dfs(vector<vector<char>>& grid, int row, int col) {
        if (grid[row][col] == '0') return;
        grid[row][col] = '0';  // set zero if seen
        for (auto [dr, dc] : directions) {
            int new_row = row + dr;
            int new_col = col + dc;
            if (
                new_row >= 0 && new_row < ROW &&
                new_col >= 0 && new_col < COL &&
                grid[new_row][new_col] == '1'
            ) {
                dfs(grid, new_row, new_col);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        ROW = grid.size(), COL = grid[0].size();
        int res = 0;
        for (int i = 0; i < ROW; ++i) {
            for (int j = 0; j < COL; ++j) {
                if (grid[i][j] == '0') continue;
                ++res;
                dfs(grid, i, j);
            }
        }
        return res;
    }
};
