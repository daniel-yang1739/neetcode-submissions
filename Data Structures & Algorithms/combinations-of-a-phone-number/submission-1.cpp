class Solution {
private:
    vector<string> chars_map = { 
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    vector<string> res;
public:
    void back_tracking(int i, string curr_str, string& digits) {
        if (i >= digits.length()) {
            res.push_back(curr_str);
            return;
        }
        string chars = chars_map[digits[i] - '0'];
        for (char c : chars) {
            back_tracking(i + 1, curr_str + c, digits);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        back_tracking(0, "", digits);
        return res;
    }
};