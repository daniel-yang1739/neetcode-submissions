func twoSum(nums []int, target int) []int {
    seen := make(map[int]int)
    for i, n := range nums {
        if _, existed := seen[target-n]; existed {
            return []int{seen[target-n], i}
        }
        seen[n] = i
    }
    return []int{-1, -1}
}
