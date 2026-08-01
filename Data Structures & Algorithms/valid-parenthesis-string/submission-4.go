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
			// too more right parenthesis
			return false
		}
		if leftMin < 0 {
			// we seem too more stars as the right parenthesis,
			// so we reset star to an empty string.
			leftMin = 0
		}
	}
	return leftMin == 0
}