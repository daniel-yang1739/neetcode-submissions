class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_char_count = defaultdict(int)
        for s_c in s:
            s_char_count[s_c] += 1
        t_char_count = defaultdict(int)
        for t_c in t:
            t_char_count[t_c] += 1
        return s_char_count == t_char_count