class Solution {
public:
    unordered_map<int, bool> memo;

    bool backTracking(
        string s, int start, 
        unordered_set<string>& wordSet
    ) {
        if (start == s.length()) {
            return true;
        }
        if (memo.count(start)) {
            return memo[start];
        }
        for (int i = start; i < s.length(); ++i) {
            string subStr = s.substr(start, i - start + 1);
            if (
                wordSet.count(subStr) && 
                backTracking(s, i + 1, wordSet)
            ) {
                return memo[start] = true;
            }
        }
        return memo[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return backTracking(s, 0, wordSet);
    }
};
