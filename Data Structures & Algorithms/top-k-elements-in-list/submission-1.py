from heapq import *
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = [0] * 2001
        for num in nums:
            count[num + 1000] += 1
        ret = []  # initialize heap
        for num, freq in enumerate(count):
            # To make max heap, we use -freq to reverse the min heap
            heappush(ret, (-freq, num - 1000))  
        return [heappop(ret)[1] for _ in range(k)]