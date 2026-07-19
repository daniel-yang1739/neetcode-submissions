class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row_size, col_size = len(matrix), len(matrix[0])
        left, right = 0, row_size
        while left < right:
            mid = (left + right) // 2
            if matrix[mid][0] < target:
                left = mid + 1
            else:
                right = mid
        if left < row_size and matrix[left][0] == target:
            return True
        if left == 0:  # avoid index -1
            return False
        target_row = left - 1
        left, right = 0, col_size
        while left < right:
            mid = (left + right) // 2
            if matrix[target_row][mid] < target:
                left = mid + 1
            else:
                right = mid
        if left < col_size and matrix[target_row][left] == target:
            return True
        return False