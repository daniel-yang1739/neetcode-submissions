class Solution {
    /**
     * @param {string[]} strs
     * @returns {string}
     */
    encode(strs) {
        let encoded_strs = '';
        for (let str of strs) {
            encoded_strs += str.length + '#' + str;
        }
        return encoded_strs;
    }

    /**
     * @param {string} str
     * @returns {string[]}
     */
    decode(str) {
        const res = [];
        let i = 0;
        while (i < str.length) {
            const start = i;
            while (str[i] !== '#') ++i;
            const strLen = parseInt(str.slice(start, i));
            i += 1;
            res.push(str.slice(i, i + strLen));
            i += strLen;
        }
        return res;
    }
}
