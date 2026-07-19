class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ROW = obstacleGrid.size(), COL = obstacleGrid[0].size();
        if (obstacleGrid[ROW - 1][COL - 1] == 1) return 0;
        vector<int> dp(COL + 1, 0);
        dp[COL - 1] = 1;
        for (int r = ROW - 1; r >= 0; --r) {
            for (int c = COL - 1; c >= 0; --c) {
                if (obstacleGrid[r][c] == 1) {
                    dp[c] = 0;
                } else {
                    dp[c] += dp[c + 1];
                }
            }
        }
        return dp[0];
    }
};