func rotate(matrix [][]int)  {
	m, n := len(matrix), len(matrix[0])
	for i := 0; i < m / 2; i++ {
		for j := i; j < n - i - 1; j++ {
			r, c := i, j
			prev, next := matrix[r][c], -1
			for k := 0; k < 4; k++{
				next = matrix[c][n-1-r]
				matrix[c][n-1-r] = prev
				prev = next
				r, c = c, n - 1 - r
			}
		}
	}
}