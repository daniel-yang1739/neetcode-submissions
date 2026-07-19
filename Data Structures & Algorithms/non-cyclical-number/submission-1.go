func isHappy(n int) bool {
    hashSet := make(map[int]bool)
	for !hashSet[n] {
		hashSet[n] = true
		n = sumOfSquare(n)
		if n == 1 {
			return true
		}
	}
	return false
}

func sumOfSquare(n int) int {	
	sum := 0
	for n > 0 {
		digit := n % 10
		sum += digit * digit
		n /= 10
	}
	return sum
}