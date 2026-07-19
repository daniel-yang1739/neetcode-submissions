class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1;
        int ROW = grid.size(), COL = grid[0].size();
        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1},
            {-1, -1}, {-1, 1}, {1, -1}, {1, 1} 
        };
        queue<pair<int, int>> que;
        que.push({0, 0});
        vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
        visited[0][0] = true;;
        int length = 1;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                auto [row, col] = que.front();
                que.pop();
                if (row == ROW - 1 && col == COL - 1) {
                    return length;
                }
                for (auto [dr, dc] : directions) {
                    int new_row = row + dr;
                    int new_col = col + dc;
                    if (
                        new_row >= 0 && new_row < ROW &&
                        new_col >= 0 && new_col < COL &&
                        grid[new_row][new_col] == 0 &&
                        !visited[new_row][new_col]
                    ) {
                        que.push({new_row, new_col});
                        visited[new_row][new_col] = true;
                    }
                }
            }
            ++length;
        }
        return -1;
    }
};