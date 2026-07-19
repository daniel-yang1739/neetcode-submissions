class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0) return true;
        int left = 0, right = s.length() - 1;
        while (left <= right) {
            if (s[left] != s[right]) return false;
            ++left, --right;
        }
        return true;
    }

    void back_tracking(
        int start, string s, 
        vector<string>& split, 
        vector<vector<string>>& res
    ) {
        if (start == s.length()) {
            res.push_back(split);
        }
        for (int end = start; end < s.length(); ++end) {
            string sub_string = s.substr(start, end - start + 1);
            if (isPalindrome(sub_string)) {
                split.push_back(sub_string);
                back_tracking(end + 1, s, split, res);
                split.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        if (s.size() == 1) return {{s}};
        vector<vector<string>> res;
        vector<string> split;
        back_tracking(0, s, split, res);
        return res;
    }
};
