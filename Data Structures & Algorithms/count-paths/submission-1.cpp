class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);
        for (int r = 0; r < m; ++r) {
            vector<int> curr(n, 0);
            curr[0] = 1;
            for (int c = 1; c < n; ++c) {
                curr[c] = curr[c - 1] + prev[c];
            }
            prev = curr;
        }
        return prev.back();
    }
};
