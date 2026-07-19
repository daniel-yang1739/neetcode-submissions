class Solution {
private:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int ROW, COL;
public:
    int areaDFS(vector<vector<int>>& grid, int row, int col) {
        if (grid[row][col] == 0) return 0;
        grid[row][col] = 0;
        int area = 1;
        for (auto [dr, dc] : directions) {
            int new_row = row + dr, new_col = col + dc;
            if (
                new_row >= 0 && new_row < ROW &&
                new_col >= 0 && new_col < COL &&
                grid[new_row][new_col] == 1
            ) {
                area += areaDFS(grid, new_row, new_col);
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROW = grid.size(), COL = grid[0].size();
        int max_area = 0;
        for (int i = 0; i < ROW; ++i) {
            for (int j = 0; j < COL; ++j) {
                if (grid[i][j] == 0) continue;
                int area = areaDFS(grid, i, j);
                max_area = max(max_area, area);
            }
        }
        return max_area;
    }
};
