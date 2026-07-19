class Solution {
public:
    void back_tracking(
        int n, int l_count, int r_count, 
        string curr, vector<string>& res
    ) {
        if (curr.length() == 2 * n) {
            res.push_back(curr);
            return;
        }
        if (l_count < n) {
            back_tracking(n, l_count + 1, r_count, curr + "(", res);
        }
        if (l_count > r_count) {
            back_tracking(n, l_count, r_count + 1, curr + ")", res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        back_tracking(n, 0, 0, "", res);
        return res;
    }
};
