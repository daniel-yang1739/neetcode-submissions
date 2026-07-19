class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> stk;
        stk.push({0, temperatures[0]});
        for (int i = 1; i < temperatures.size(); ++i) {
            while (!stk.empty() && stk.top().second < temperatures[i]) {
                auto [idx, t] = stk.top();
                res[idx] = i - idx;
                stk.pop();
            }
            stk.push({i, temperatures[i]});
        }
        return res;
    }
};
