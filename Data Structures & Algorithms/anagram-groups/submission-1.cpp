class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> code_to_anagrams;
        for (string str : strs) {
            vector<int> count(26, 0);
            for (char c : str) ++count[c - 'a'];
            string code = to_string(count[0]);
            for (int val : count) code += "," + to_string(val);
            code_to_anagrams[code].push_back(str);
        }
        vector<vector<string>> ret;
        for (auto& pair : code_to_anagrams) {
            ret.push_back(pair.second);
        }
        return ret;
    }
};
