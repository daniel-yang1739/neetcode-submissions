class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_to_index = {}
        for i, num in enumerate(nums):
            if num_to_index.get(target - num) is not None:
                return [num_to_index[target - num], i];
            num_to_index[num] = i