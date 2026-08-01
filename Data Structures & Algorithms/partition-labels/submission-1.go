func partitionLabels(s string) []int {
	lastPos := make([]int, 26)
	for i := 0; i < len(s); i++ {
		lastPos[s[i]-'a'] = i
	}
	res := []int{}
	start, end := 0, 0
	for i := 0; i < len(s); i++ {
		end = max(end, lastPos[s[i]-'a'])
		if i == end {
			res = append(res, end - start + 1)
			start = i + 1
		}
	}
	return res
}
