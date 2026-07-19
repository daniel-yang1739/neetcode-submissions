func plusOne(digits []int) []int {
    n := len(digits)
	digits[n-1] += 1
	carry := 0
	for i := n - 1; i >= 0; i-- {
		digits[i] += carry
		carry = digits[i] / 10
		digits[i] %= 10
	}
	if carry == 0 {
		return digits
	}
	res := make([]int, n + 1)
	res[0] = 1
	for i := 1; i < n + 1; i++ {
		res[i] = digits[i-1]
	}
	return res
}
