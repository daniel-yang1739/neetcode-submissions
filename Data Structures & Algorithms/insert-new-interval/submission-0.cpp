class Solution {
public:
    vector<vector<int>> insert(
        vector<vector<int>>& intervals, vector<int>& newInterval
    ) {
        int N = intervals.size();
        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        vector<vector<int>> res;
        for (int i = 0; i < N; ++i) {
            if (intervals[i][1] < newStart) {
                res.push_back(intervals[i]);
            } else if (intervals[i][0] > newEnd) {
                res.push_back({newStart, newEnd});
                while (i < N) {
                    res.push_back(intervals[i]);
                    ++i;
                }
                return res;
            } else {
                newStart = min(newStart, intervals[i][0]);
                newEnd = max(newEnd, intervals[i][1]);
            }
        }
        res.push_back({newStart, newEnd});
        return res;
    }
};
