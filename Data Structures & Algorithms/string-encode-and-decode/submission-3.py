class Solution:
    def encode(self, strs: List[str]) -> str:
        res = ''
        for s in strs:
            res += str(len(s)) + '#' + s
        return res
    
    def decode(self, s: str) -> List[str]:
        res = []
        i = 0
        while (i < len(s)):
            start = i
            while (s[i] != '#'): 
                i += 1
            str_len = int(s[start:i])
            i += 1
            res.append(s[i:i+str_len])
            i += str_len
        return res
