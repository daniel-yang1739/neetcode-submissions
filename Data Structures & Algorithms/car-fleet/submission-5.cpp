class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pos_speed;
        for (int i = 0; i < position.size(); ++i) {
            pos_speed.push_back({position[i], speed[i]});
        }
        sort(pos_speed.begin(), pos_speed.end());
        stack<double> stk;
        for (int i = pos_speed.size() - 1; i >= 0; --i) {
            double distance = target - pos_speed[i].first;
            double speed = pos_speed[i].second;
            double time = distance / speed;
            if (stk.empty() || time > stk.top()) {
                stk.push(time);
            }
        }
        return stk.size();
    }
};
