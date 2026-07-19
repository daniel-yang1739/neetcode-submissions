class Solution:
    def search(self, nums: List[int], target: int) -> int:
        nums.sort()
        left, right = 0, len(nums)
        while left < right:
            mid = (left + right) // 2
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid
        return left if left < len(nums) and nums[left] == target else -1