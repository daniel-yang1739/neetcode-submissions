class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        vector<int> s1_count(26, 0);
        for (char c : s1) ++s1_count[c - 'a'];
        vector<int> window_count(26, 0);
        for (int R = 0; R < s2.length(); ++R) {
            ++window_count[s2[R] - 'a'];
            if (R >= s1.length() - 1) {
                if (window_count == s1_count) {
                    return true;
                }
                int left = R - s1.length() + 1;
                --window_count[s2[left] - 'a'];
            }
        }
        return false;
    }
};
