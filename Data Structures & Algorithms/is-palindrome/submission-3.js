class Solution {
    /**
     * @param {string} s
     * @return {boolean}
     */
    isalnum(str) {
        const regexObj = /^[a-zA-Z0-9]+$/
        return regexObj.test(str);
    }

    isPalindrome(s) {
        let left = 0, right =s.length - 1;
        while (left < right) {
            while (left < right && !this.isalnum(s[left])) ++left;
            while (left < right && !this.isalnum(s[right])) --right;
            if (s[left].toLowerCase() !== s[right].toLowerCase()) return false;
            ++left, --right;
        }
        return true;
    }
}
