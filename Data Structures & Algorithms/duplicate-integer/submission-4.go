func hasDuplicate(nums []int) bool {
    seen := make(map[int]bool)
    for _, n := range nums {
        if _, existed := seen[n]; existed {
            return true
        }
        seen[n] = true
    }
    return false
}
