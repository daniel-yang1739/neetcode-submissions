func merge(intervals [][]int) [][]int {
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})
	N := len(intervals)
	merged := [][]int{}
	for i := 0; i < N; i++ {
		curr := intervals[i]
		for i < N - 1 && curr[1] >= intervals[i+1][0] {
			curr[1] = max(curr[1], intervals[i+1][1])
			i++
		}
		merged = append(merged, curr)
	}
	return merged
}