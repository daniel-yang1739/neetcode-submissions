class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) return "";
        unordered_map<char, int> targetMap;
        for (char c : t) {
            ++targetMap[c];
        }
        int minStart = 0, minLen = INT_MAX;
        unordered_map<char, int> windowMap;
        int have = 0, need = targetMap.size();
        int start = 0;
        for (int end = 0; end < s.length(); ++end) {
            if (targetMap.count(s[end])) {
                ++windowMap[s[end]];
                if (windowMap[s[end]] == targetMap[s[end]]) {
                    ++have;
                }
            }
            while (have == need) {
                if (end - start + 1 < minLen) {
                    minStart = start;
                    minLen = end - start + 1;
                }
                if (targetMap.count(s[start])) {
                    --windowMap[s[start]];
                    if (windowMap[s[start]] < targetMap[s[start]]){
                        --have;
                    }
                    if (windowMap[s[start]] == 0) {
                        windowMap.erase(s[start]);
                    }
                }
                ++start;
            }
        }
        return minLen != INT_MAX ? s.substr(minStart, minLen) : "";
    }
};
