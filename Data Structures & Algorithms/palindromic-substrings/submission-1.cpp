class Solution {
public:
    int countPalin(string s, int l, int r) {
        int res = 0;
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            ++res;
            --l;
            ++r;
        }
        return res;
    }
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); ++i) {
            // odd length
            res += countPalin(s, i, i);
            // even length
            res += countPalin(s, i, i + 1);
        }
        return res;
    }
};
