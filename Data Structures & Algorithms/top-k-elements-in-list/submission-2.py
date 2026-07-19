from heapq import *
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = [0] * 2001
        for num in nums:
            counts[num + 1000] += 1
        buckets = [[] for _ in range(len(nums) + 1)]  # bucket sort
        for num, freq in enumerate(counts):
            buckets[freq].append(num - 1000)
        ret = []
        for i in range(len(buckets) - 1, 0, -1):
            for num in buckets[i]:
                ret.append(num)
                if len(ret) == k:
                    return ret