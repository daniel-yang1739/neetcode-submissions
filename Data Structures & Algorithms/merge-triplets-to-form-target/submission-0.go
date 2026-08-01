func mergeTriplets(triplets [][]int, target []int) bool {
	res := []int{0, 0, 0}
	for _, t := range triplets {
		if t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2] {
			res[0] = max(res[0], t[0])
			res[1] = max(res[1], t[1])
			res[2] = max(res[2], t[2])
		}
		if res[0] == target[0] && res[1] == target[1] && res[2] == target[2] {
			return true
		}
	}
	return false
}
