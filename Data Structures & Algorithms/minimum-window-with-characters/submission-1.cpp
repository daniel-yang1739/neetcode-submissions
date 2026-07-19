class Solution {
public:
    bool isValid(
        unordered_map<char, int>& currMap, 
        unordered_map<char, int>& targetMap
    ) {
        for (auto it : targetMap) {
            if (currMap[it.first] < targetMap[it.first]) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        if (t.length() > s.length()) return "";
        unordered_map<char, int> targetMap;
        for (char c : t) {
            ++targetMap[c];
        }
        int minStart = 0, minLen = INT_MAX;
        unordered_map<char, int> currMap;
        int start = 0;
        for (int end = 0; end < s.length(); ++end) {
            if (targetMap.count(s[end])) {
                ++currMap[s[end]];
            }
            while (isValid(currMap, targetMap)) {
                if (end - start + 1 < minLen) {
                    minStart = start;
                    minLen = end - start + 1;
                }
                if (targetMap.count(s[start])) {
                    --currMap[s[start]];
                    if (currMap[s[start]] == 0) {
                        currMap.erase(s[start]);
                    }
                }
                ++start;
            }
        }
        return minLen != INT_MAX ? s.substr(minStart, minLen) : "";
    }
};
