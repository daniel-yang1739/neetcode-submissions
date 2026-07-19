class Solution {
    /**
     * @param {string[]} strs
     * @return {string[][]}
     */
    groupAnagrams(strs) {
        const codeToAnagrams = new Map();
        for (let str of strs) {
            const count = new Array(26).fill(0);
            for (let c of str) {
                count[c.charCodeAt(0) - 'a'.charCodeAt(0)] += 1;
            }
            const code = count.join(',');
            if (!codeToAnagrams.has(code)) {
                codeToAnagrams.set(code, new Array());
            }
            codeToAnagrams.get(code).push(str);
        }
        return Array.from(codeToAnagrams.values());
    }
}
