class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > minHeap;
        vector<pair<int, int>> directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };
        vector<vector<int>> shortest(R, vector<int>(C, -1));
        minHeap.push({grid[0][0], 0, 0});  // {weight, row, col}
        while (!minHeap.empty()) {
            auto [w, row, col] = minHeap.top();
            minHeap.pop();
            if (shortest[row][col] != -1) {
                continue;
            }
            shortest[row][col] = w;
            for (const auto& [dr, dc] : directions) {
                int new_row = row + dr;
                int new_col = col + dc;
                if (
                    new_row >= 0 && new_row < R &&
                    new_col >= 0 && new_col < C &&
                    shortest[new_row][new_col] == -1
                ) {
                    minHeap.push({
                        // IMPORTENT !! ex: 8->7 => 8
                        max(w, grid[new_row][new_col]), 
                        new_row, new_col
                    });
                }
            }
        }
        return shortest[R - 1][C - 1];
    }
};
