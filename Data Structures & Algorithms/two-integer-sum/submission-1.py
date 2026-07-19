class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_to_index = {}
        for i in range(len(nums)):
            if num_to_index.get(target - nums[i]) is not None:
                return [num_to_index[target - nums[i]], i];
            num_to_index[nums[i]] = i