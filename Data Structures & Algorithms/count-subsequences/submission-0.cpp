class Solution {
public:
    vector<vector<int>> memo;
    int memoization(int sIdx, int tIdx, string& s, string& t) {
        if (tIdx == t.length()) {
            return 1;
        }

        if (sIdx == s.length()) {
            return 0;
        }

        if (memo[sIdx][tIdx] != -1) {
            return memo[sIdx][tIdx];
        }

        int res = memoization(sIdx + 1, tIdx, s, t);
        if (s[sIdx] == t[tIdx]) {
            res += memoization(sIdx + 1, tIdx + 1, s, t);
        }
        return memo[sIdx][tIdx] = res;
    }

    int numDistinct(string s, string t) {
        memo = vector<vector<int>>(s.length(), vector<int>(t.length(), -1));
        return memoization(0, 0, s, t);
    }
};
