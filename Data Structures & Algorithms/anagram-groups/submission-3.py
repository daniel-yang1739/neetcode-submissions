class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        code_to_anagrams = defaultdict(list)
        for string in strs:
            count = [0] * 26
            for c in string:
                count[ord(c) - ord('a')] += 1
            code_to_anagrams[tuple(count)].append(string)
        return list(code_to_anagrams.values())