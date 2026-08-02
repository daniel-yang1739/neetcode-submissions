func majorityElement(nums []int) int {
    majority, vote := 0, 0
    for _, num := range nums {
        if vote == 0 {
            majority = num
        }
        if num != majority {
            vote--
        } else {
            vote++
        }
    }
    return majority
}