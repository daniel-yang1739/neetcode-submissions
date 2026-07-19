class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        unordered_set<char> char_set;
        int left = 0, max_len = 1, curr_len = 1;
        char_set.insert(s[0]);
        for (int right = 1; right < s.length(); ++right) {
            while (char_set.count(s[right]) > 0) {
                char_set.erase(s[left]);
                --curr_len;
                ++left;
            }
            char_set.insert(s[right]);
            ++curr_len;
            max_len = max(max_len, curr_len);
        }
        return max_len;
    }
};
