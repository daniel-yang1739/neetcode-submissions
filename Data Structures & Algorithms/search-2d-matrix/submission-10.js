class Solution {
    /**
     * @param {number[][]} matrix
     * @param {number} target
     * @return {boolean}
     */
    searchMatrix(matrix, target) {
        const rowSize = matrix.length, colSize = matrix[0].length;
        let left = 0, right = rowSize;
        while (left < right) {
            let mid = left + Math.floor((right - left) / 2);
            if (matrix[mid][0] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (left < rowSize && matrix[left][0] === target) return true;
        if (left === 0) return false;  // avoid index -1
        let targetRow = left - 1;
        left = 0, right = colSize;
        while (left < right) {
            let mid = left + Math.floor((right - left) / 2);
            if (matrix[targetRow][mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (left < colSize && matrix[targetRow][left] == target) return true;
        return false;
    }
}
