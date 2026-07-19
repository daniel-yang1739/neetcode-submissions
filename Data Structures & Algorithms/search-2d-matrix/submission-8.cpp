class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_size = matrix.size(), col_size = matrix[0].size();
        int left = 0, right = row_size;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid][0] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (left < row_size && matrix[left][0] == target) return true;
        if (left == 0) return false;
        int target_row = left - 1;
        left = 0, right = col_size;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (matrix[target_row][mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (left < col_size && matrix[target_row][left] == target) return true;
        return false;
    }
};
