class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow = fast = nums[0]
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break
        # Floyd's Cycle Detection
        slow2 = nums[0]
        while True:
            if slow == slow2:
                break
            slow = nums[slow]
            slow2 = nums[slow2]
        return slow2