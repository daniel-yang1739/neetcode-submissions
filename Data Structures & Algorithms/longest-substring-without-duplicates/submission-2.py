class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        left, max_len, curr_len = 0, 1, 1
        char_set = set()
        char_set.add(s[0])
        right = 1
        while right < len(s):
            while s[right] in char_set:
                char_set.remove(s[left])
                curr_len -= 1
                left += 1
            char_set.add(s[right])
            curr_len += 1
            max_len = max(max_len, curr_len)
            right += 1
        return max_len