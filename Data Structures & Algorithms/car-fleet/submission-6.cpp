class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pos_speed;
        for (int i = 0; i < position.size(); ++i) {
            pos_speed.push_back({position[i], speed[i]});
        }
        sort(pos_speed.rbegin(), pos_speed.rend());  // reverse
        stack<double> stk;
        for (int i = 0; i < pos_speed.size(); ++i) {
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
