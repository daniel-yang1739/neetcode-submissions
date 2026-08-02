func removeElement(nums []int, val int) int {
    n, valCount := len(nums), 0
    for i := 0; i < n; i++ {
        if nums[i] == val {
            valCount++
        } else {
            tIdx := i - valCount
            nums[i], nums[tIdx] = nums[tIdx], nums[i]
        }
    }
    return n - valCount
}
