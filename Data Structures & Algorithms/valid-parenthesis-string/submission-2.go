func checkValidString(s string) bool {
	lCount, sCount := 0, 0
	for i := 0; i < len(s); i++ {
		if s[i] == '(' {
			lCount++
		} else if s[i] == '*' {
			sCount++
		} else {
			if lCount > 0 {
				lCount--
			} else if sCount > 0 {
				sCount--
			} else {
				return false
			}
		}
	}
	rCount, sCount := 0, 0
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == ')' {
			rCount++
		} else if s[i] == '*' {
			sCount++
		} else {
			if rCount > 0 {
				rCount--
			} else if sCount > 0 {
				sCount--
			} else {
				return false
			}
		}
	}
	return true
}