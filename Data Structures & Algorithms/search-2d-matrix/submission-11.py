class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row_size, col_size  = len(matrix), len(matrix[0])
        left, right = 0, row_size * col_size
        while left < right:
            mid = (left + right) // 2
            row, col = mid // col_size, mid % col_size
            if matrix[row][col] < target:
                left = mid + 1
            else:
                right = mid
        row, col = left // col_size, left % col_size
        if left < row_size * col_size and matrix[row][col] == target:
            return True
        return False