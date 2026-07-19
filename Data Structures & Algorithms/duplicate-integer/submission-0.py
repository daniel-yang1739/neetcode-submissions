class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        num_count = defaultdict(int)
        for num in nums:
            num_count[num] += 1
            if num_count[num] > 1:
                return True
        return False