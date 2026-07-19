class Solution {
public:
    int characterReplacement(string s, int k) {
        int L = 0, max_count = 0, max_length = 0;
        unordered_map<char, int> count;
        for (int R = 0; R < s.length(); ++R) {
            ++count[s[R]];
            max_count = max(max_count, count[s[R]]);
            while (R - L + 1 - max_count > k) {
                --count[s[L]];
                ++L;
            }
            max_length = max(max_length, R - L + 1);
        }
        return max_length;
    }
};
