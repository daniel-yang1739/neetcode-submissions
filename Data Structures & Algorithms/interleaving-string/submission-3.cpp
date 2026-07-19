class Solution {
public:
    bool backtracking(
        string s1, string s2, string& s3, 
        int i, int j, int k,
        vector<vector<int>>& memo
    ) {
        if (k == s3.length()) return true;
        if (memo[i][j] != -1) {
            return memo[i][j] == 1;
        }
        bool result = false;
        if (i < s1.length() && s1[i] == s3[k]) {
            result = backtracking(s1, s2, s3, i + 1, j, k + 1, memo);
        }
        if (!result && j < s2.length() && s2[j] == s3[k]) {
            result = backtracking(s1, s2, s3, i, j + 1, k + 1, memo);
        }
        memo[i][j] = result ? 1 : 0;
        return result;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        vector<vector<int>> memo(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        return backtracking(s1, s2, s3, 0, 0, 0, memo);
    }
};
