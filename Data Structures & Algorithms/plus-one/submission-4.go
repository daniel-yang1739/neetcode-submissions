func plusOne(digits []int) []int {
    reverse(digits)
	carry := 0
	digits[0] += 1
	for i := 0; i < len(digits); i++ {
		digits[i] += carry
		carry = digits[i] / 10
		digits[i] %= 10
	}
	if carry == 1 {
		digits = append(digits, carry)
	}
	reverse(digits)
	return digits
}

func reverse(arr []int) {
	L, R := 0, len(arr) - 1
	for L < R {
		arr[L], arr[R] = arr[R], arr[L]
		R--
		L++
	}
}
