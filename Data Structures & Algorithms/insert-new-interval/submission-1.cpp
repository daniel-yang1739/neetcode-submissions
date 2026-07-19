class Solution {
public:
    vector<vector<int>> insert(
        vector<vector<int>>& intervals, vector<int>& newInterval
    ) {
        int N = intervals.size();
        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        vector<vector<int>> res;

        int i = 0;
        while (i < N && intervals[i][1] < newStart) {
            res.push_back(intervals[i]);
            ++i;
        }

        while (
            i < N && 
            intervals[i][1] >= newStart && 
            intervals[i][0] <= newEnd
        ) {
            newStart = min(newStart, intervals[i][0]);
            newEnd = max(newEnd, intervals[i][1]);
            ++i;
        }
        res.push_back({newStart, newEnd});
        
        while (i < N && intervals[i][0] > newEnd) {
            res.push_back(intervals[i]);
            ++i;
        }

        return res;
    }
};
