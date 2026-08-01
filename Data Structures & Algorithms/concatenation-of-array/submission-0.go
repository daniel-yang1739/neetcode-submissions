func getConcatenation(nums []int) []int {
    n := len(nums)
    res := make([]int, 2 * n)
    for i := range nums {
        res[i] = nums[i]
        res[i+n] = nums[i]
    }
    return res
}