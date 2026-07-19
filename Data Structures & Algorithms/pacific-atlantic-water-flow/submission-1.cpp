class Solution {
private:
    int ROW, COL;
    vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    void canToOceanDFS(
        int row, int col, 
        vector<vector<int>>& heights,
        vector<vector<bool>>& ocean
    ) {
        ocean[row][col] = true;
        for (auto& [dr, dc] : directions) {
            int new_row = row + dr;
            int new_col = col + dc;
            if (
                new_row >= 0 && new_row < ROW &&
                new_col >= 0 && new_col < COL &&
                !ocean[new_row][new_col] &&
                heights[new_row][new_col] >= heights[row][col]
            ) {
                canToOceanDFS(new_row, new_col, heights, ocean);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROW = heights.size(), COL = heights[0].size();
        vector<vector<bool>> pacific(ROW, vector<bool>(COL, false));
        vector<vector<bool>> atlantic(ROW, vector<bool>(COL, false));
        for (int r = 0; r < ROW; ++r) {
            canToOceanDFS(r, 0, heights, pacific);
            canToOceanDFS(r, COL - 1, heights, atlantic);
        }
        for (int c = 0; c < COL; ++c) {
            canToOceanDFS(0, c, heights, pacific);
            canToOceanDFS(ROW - 1, c, heights, atlantic);
        }
        vector<vector<int>> res;
        for (int r = 0; r < ROW; ++r) {
            for (int c = 0; c < COL; ++c) {
                if (pacific[r][c] && atlantic[r][c]) {
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }
};
