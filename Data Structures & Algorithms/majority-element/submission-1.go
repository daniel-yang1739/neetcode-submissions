func majorityElement(nums []int) int {
    majority, mCount := nums[0], 0
    for _, num := range nums {
        if mCount == 0 {
            majority = num
        }
        if num != majority {
            mCount--
        } else {
            mCount++
        }
    }
    return majority
}