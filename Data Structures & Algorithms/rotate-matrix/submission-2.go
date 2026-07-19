func rotate(matrix [][]int)  {
	m, n := len(matrix), len(matrix[0])
    //Transpose (Diag Flip)
    for i := 0; i < m; i++ {
        for j := i + 1; j < n; j++ {
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        }
    }
    // Horizontal Flip
    for i := 0; i < m; i++ {
        for j := 0; j < n / 2; j++ {
            matrix[i][j], matrix[i][n-j-1] = matrix[i][n-j-1], matrix[i][j]
        }
    }
}