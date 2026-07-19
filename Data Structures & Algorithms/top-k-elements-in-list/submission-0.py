class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = [0] * 2001
        for num in nums:
            count[num + 1000] += 1
        ret = list(range(-1000, 1000))
        ret.sort(key=lambda x: count[x + 1000], reverse=True)
        return ret[:k]