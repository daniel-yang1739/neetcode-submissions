class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int maxLen = 0;
        for (int i = 0; i < s.length(); ++i) {
            // odd length;
            int l = i, r = i;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                int len = r - l + 1;
                if (len > maxLen) {
                    res = s.substr(l, len);
                    maxLen = len;
                }
                --l;
                ++r;
            }
            // even length;
            l = i, r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                int len = r - l + 1;
                if (len > maxLen) {
                    res = s.substr(l, len);
                    maxLen = len;
                }
                --l;
                ++r;
            }
        }
        return res;
    }
};
