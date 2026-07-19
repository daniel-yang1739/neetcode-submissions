func spiralOrder(matrix [][]int) []int {
	m, n, idx := len(matrix), len(matrix[0]), 0
	res := make([]int, m * n)
	for i := 0; i <= m / 2; i++ {
		r, c := i, i
		for idx < m * n && c < n - i - 1 {
			res[idx] = matrix[r][c]
			c++
			idx++
		}
		for idx < m * n && r < m - i - 1 {
			res[idx] = matrix[r][c]
			r++
			idx++
		}
		for idx < m * n && c > i {
			res[idx] = matrix[r][c]
			c--
			idx++
		}
		for idx < m * n && r > i {
			res[idx] = matrix[r][c]
			r--
			idx++
		}
		if idx < m * n && (m * n) % 2 != 0 && i == m / 2 {
			res[idx] = matrix[r][c]
			idx++
		}
	}
	return res
}