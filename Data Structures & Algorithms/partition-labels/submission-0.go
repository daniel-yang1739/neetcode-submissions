type Interval struct {
	start, end int
}

func partitionLabels(s string) []int {
	charInterval := make([]Interval, 26)
	for i := range charInterval {
		charInterval[i].start = -1
		charInterval[i].end = -1
	}
	for i := range s {
		idx := s[i] - 'a'
		if charInterval[idx].start == -1 {
			charInterval[idx].start = i
		}
		charInterval[idx].end = i
	}
	sort.Slice(charInterval, func(i, j int) bool {
		if charInterval[i].start != charInterval[j].start {
			return charInterval[i].start < charInterval[j].start
		}
		return charInterval[i].end < charInterval[j].end
	})
	startIdx := 0
	for charInterval[startIdx].start == -1 {
		startIdx++
	}
	res := []int{}
	for i := startIdx; i < len(charInterval); i++ {
		if i == len(charInterval) - 1 || charInterval[i+1].start > charInterval[i].end {
			res = append(res, charInterval[i].end - charInterval[i].start + 1)
			continue
		}
		charInterval[i+1].start = charInterval[i].start
		charInterval[i+1].end = max(charInterval[i].end, charInterval[i+1].end)
	}
	return res
}
