class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ROW = obstacleGrid.size(), COL = obstacleGrid[0].size();
        vector<int> prev(COL, 0);
        prev[0] = 1;  // for the grid[0][0] initialization
        for (int r = 0; r < ROW; ++r) {
            vector<int> curr(COL, 0);
            curr[0] = obstacleGrid[r][0] == 0 ? prev[0] : 0;
            for (int c = 1; c < COL; ++c) {
                if (obstacleGrid[r][c] == 1) continue;
                curr[c] = curr[c - 1] + prev[c];
            }
            prev = curr;
        }
        return prev.back();
    }
};