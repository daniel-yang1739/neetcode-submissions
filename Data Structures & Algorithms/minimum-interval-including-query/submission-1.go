func minInterval(intervals [][]int, queries []int) []int {
	sort.Slice(intervals, func(i, j int) bool {
		if intervals[i][0] < intervals[j][0] {
			return true
		}
		return intervals[i][1] < intervals[j][1]
	})
	res := make([]int, len(queries))
	for i, q := range queries {
		res[i] = math.MaxInt32
		for _, interval := range intervals {
			L, R := interval[0], interval[1]
			if q < L || q > R {
				continue
			} else {
				res[i] = min(res[i], R - L + 1)
			}
		}
		if res[i] == math.MaxInt32 {
			res[i] = -1
		}
	}
	return res
}
