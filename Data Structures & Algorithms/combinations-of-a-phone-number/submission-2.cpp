class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res = {""};
        vector<string> chars_map = { 
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        for (char digit : digits) {
            vector<string> tmp;
            for (string& curr_str : res) {
                for (char c : chars_map[digit - '0']) {
                    tmp.push_back(curr_str + c);
                }
            }
            res = tmp;
        }
        return res;
    }
};