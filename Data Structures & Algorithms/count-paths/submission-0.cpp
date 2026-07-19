class Solution {
    int row_size, col_size;
public:
    int uniquePaths(int m, int n) {
        row_size = m, col_size = n;
        vector<vector<int>> cache(m, vector<int>(n, 0));
        return memoization(0, 0, cache);
    }
    
    int memoization(int row, int col, vector<vector<int>>& cache) {
        if (row == row_size - 1 || col == col_size - 1) {
            return 1;
        }
        if (cache[row][col] > 0) {
            return cache[row][col];
        }
        cache[row][col] = (
            memoization(row + 1, col, cache) + 
            memoization(row, col + 1, cache)
        );
        return cache[row][col];
    }
};
