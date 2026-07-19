class Solution {
public:
    vector<int> countBits(int n) {
        int latestTwoPow = 2;
        vector<int> res(n + 1);
        res[0] = 0, res[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (latestTwoPow * 2 == i) {
                latestTwoPow *= 2;
            }
            res[i] = res[i - latestTwoPow] + 1;
        }
        return res;
    }
};
