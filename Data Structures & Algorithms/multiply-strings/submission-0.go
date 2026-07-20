func multiply(num1 string, num2 string) string {
    if num1 == "0" || num2 == "0" {
		return "0"
	}
	m, n := len(num1), len(num2)
	res := make([]int, m + n)
	for i := m - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			pos := (m - 1 - i) + (n - 1 - j)
			mul := int(num1[i] - '0') * int(num2[j] - '0')
			res[pos] += mul
			res[pos+1] += res[pos] / 10
			res[pos] %= 10
		}
	}
	
	start := len(res) - 1
	for start >= 0 && res[start] == 0 {
		start--
	}
	if start < 0 {
		return "0"
	}

	resBytes := make([]byte, start + 1)
	for i := start; i >= 0; i-- {
		resBytes[start - i] = byte('0' + res[i])
	}
	return string(resBytes)
}
