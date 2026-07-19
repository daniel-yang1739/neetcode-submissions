class Solution {
public:
    vector<int> countBits(int n) {
        int offset = 1;  // the less or equal and latest two power number
        vector<int> res(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            if (offset * 2 == i) {
                offset *= 2;
            }
            res[i] = res[i - offset] + 1;
        }
        return res;
    }
};
