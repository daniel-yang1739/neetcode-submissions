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
        for (int i = curr; i < candidates.size(); ++i) {
            // skip only when didn't chose the duplicated num
            if (i > curr && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (sum + candidates[i] > target) {
                break;
            }
            comb.push_back(candidates[i]);
            back_tracking(
                i + 1, sum + candidates[i],
                target, comb, candidates, res
            );
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> comb;
        back_tracking(0, 0, target, comb, candidates, res);
        return res;
    }
};
