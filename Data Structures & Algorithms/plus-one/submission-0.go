func plusOne(digits []int) []int {
    n := len(digits)
	res := make([]int, n + 1)
	for i := 1; i < n + 1; i++ {
		res[i] = digits[i-1]
	}
	res[n] += 1
	carry := 0
	for i := n; i >= 0; i-- {
		res[i] += carry
		carry = res[i] / 10
		res[i] %= 10
	}
	if res[0] == 0 {
		res = res[1:]
	}
	return res
}
