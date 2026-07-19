class Solution {
    /**
     * @param {string} s
     * @return {number}
     */
    lengthOfLongestSubstring(s) {
        if (s.length == 0) return 0;
        let left = 0, maxLen = 1, currLen = 1;
        let charSet = new Set();
        charSet.add(s[0]);
        for (let right = 1; right < s.length; ++right) {
            while (charSet.has(s[right])) {
                charSet.delete(s[left]);
                --currLen;
                ++left;
            }
            charSet.add(s[right]);
            ++currLen;
            maxLen = Math.max(maxLen, currLen);
        }
        return maxLen;
    }
}
