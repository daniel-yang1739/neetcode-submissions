func checkValidString(s string) bool {
	// the min / max count of possible unmatched '('
	leftMin, leftMax := 0, 0
	for i := range s {
		if s[i] == '(' {
			leftMin++
			leftMax++
		} else if s[i] == ')' {
			leftMin--
			leftMax--
		} else {
			leftMin--
			leftMax++
		}
		if leftMax < 0 {
			return false
		}
		if leftMin < 0 {
			leftMin = 0
		}
	}
	return leftMin == 0
}