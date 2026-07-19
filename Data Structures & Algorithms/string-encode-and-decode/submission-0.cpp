class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_strs = "";
        for (string str : strs) {
            encoded_strs += to_string(str.length()) + "#" + str;
        }
        return encoded_strs;
    }

    vector<string> decode(string s) {
        vector<string> ret;
        for (int i = 0; i < s.length(); ++i) {
            int start = i;
            while (s[i] != '#') ++i;
            int str_len = stoi(s.substr(start,  i - start));
            ret.push_back(s.substr(i + 1, str_len));
            i += str_len;
        }
        return ret;
    }
};
