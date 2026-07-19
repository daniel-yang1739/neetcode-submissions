class Solution {
private:
    vector<vector<int>> memo;
public:
    int dfs(int l, int r, vector<int> nums) {
        if (l > r) {
            return 0;
        }

        if (memo[l][r] != -1) {
            return memo[l][r];
        }

        memo[l][r] = 0;
        for (int i = l; i <= r; ++i) {
            int coins = (
                // assume nums[i] is the latest to pop
                nums[l - 1] * nums[i] * nums[r + 1] + 
                dfs(l, i - 1, nums) + 
                dfs(i + 1, r, nums)
            );
            memo[l][r] = max(memo[l][r], coins);
        }
        return memo[l][r];
    }

    int maxCoins(vector<int>& nums) {
        int N = nums.size();
        vector<int> newNums(N + 2, 1);
        memo = vector<vector<int>>(N + 2, vector<int>(N + 2, -1));
        for (int i = 1; i <= nums.size(); ++i) {
            newNums[i] = nums[i - 1];
        }
        return dfs(1, N, newNums);
    }
};
