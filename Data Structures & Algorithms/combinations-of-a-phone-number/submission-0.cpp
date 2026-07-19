class Solution {
private:
    unordered_map<char, string> chars_map = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
public:
    void back_tracking(
        int i, 
        string& digits, 
        string& curr_str, 
        vector<string>& res
    ) {
        if (i >= digits.length()) {
            res.push_back(curr_str);
            return;
        }
        string possible_str = chars_map[digits[i]];
        for (int j = 0; j < possible_str.length(); ++j) {
            curr_str.push_back(possible_str[j]);
            back_tracking(i + 1, digits, curr_str, res);
            curr_str.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (!digits.length()) return {};
        vector<string> res;
        string curr_str = "";
        back_tracking(0, digits, curr_str, res);
        return res;
    }
};
