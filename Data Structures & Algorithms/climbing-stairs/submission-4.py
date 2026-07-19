class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n
        last_2, last_1 = 1, 2
        for _ in range(n - 2):
            tmp = last_2 + last_1
            last_2 = last_1
            last_1 = tmp
        return last_1
