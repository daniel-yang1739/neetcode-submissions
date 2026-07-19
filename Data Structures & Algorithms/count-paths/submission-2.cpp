class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);
        for (int r = m - 1; r >= 0; --r) {
            vector<int> curr(n, 0);
            curr[n - 1] = 1;
            for (int c = n - 2; c >= 0; --c) {
                curr[c] = curr[c + 1] + prev[c];
            }
            prev = curr;
        }
        return prev[0];
    }
};
