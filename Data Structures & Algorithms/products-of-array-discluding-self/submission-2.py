class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        nums_len = len(nums)
        res = [1] * nums_len
        for i in range(1, nums_len, 1):
            res[i] = res[i - 1] * nums[i - 1]
        postfix = 1
        for i in range(nums_len - 1, -1, -1):
            res[i] *= postfix
            postfix *= nums[i]
        return res