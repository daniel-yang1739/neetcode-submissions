class Solution {
public:
    void back_tracking(
        int curr, int sum, int target,
        vector<int>& comb,
        vector<int>& candidates,
        vector<vector<int>>& res
    ) {
        if (sum == target) {
            res.push_back(comb);
            return;
        }
        if (curr >= candidates.size()) return;
        if (sum + candidates[curr] <= target) {
            comb.push_back(candidates[curr]);
            back_tracking(
                curr + 1, sum + candidates[curr], 
                target, comb, candidates, res
            );
            comb.pop_back();
        }
        while (
            curr + 1 < candidates.size() && 
            candidates[curr] == candidates[curr + 1]
        ) {
            ++curr;
        }
        back_tracking(
            curr + 1, sum, 
            target, comb, candidates, res
        );
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> comb;
        back_tracking(0, 0, target, comb, candidates, res);
        return res;
    }
};
