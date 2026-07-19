class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> stk;
        int max_area = 0;
        for (int i = 0; i < heights.size(); ++i) {
            int idx = i;
            while (!stk.empty() && stk.top().second > heights[i]) {
                pair<int, int> top = stk.top();
                max_area = max(
                    max_area, (i - top.first) * top.second);
                idx = top.first;
                stk.pop();
            }
            stk.push({idx, heights[i]});
        }
        int size = heights.size();
        while (!stk.empty()) {
            pair<int, int> top = stk.top();
            max_area = max(
                max_area, (size - top.first) * top.second);
            stk.pop();
        }
        return max_area;
    }
};
