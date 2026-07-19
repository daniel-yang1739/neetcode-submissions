from heapq import *
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        num_to_freq = defaultdict(int)
        for num in nums:
            num_to_freq[num] += 1
        buckets = [[] for _ in range(len(nums) + 1)]  # bucket sort
        for num, freq in num_to_freq.items():
            buckets[freq].append(num)
        ret = []
        for i in range(len(buckets) - 1, 0, -1):
            for num in buckets[i]:
                ret.append(num)
                if len(ret) == k:
                    return ret