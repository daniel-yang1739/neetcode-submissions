class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int, int> pos_speed;
        for (int i = 0; i < position.size(); ++i) {
            pos_speed[position[i]] = speed[i];
        }
        sort(position.begin(), position.end());
        stack<double> stk;
        for (int i = position.size() - 1; i >= 0; --i) {
            double distance = target - position[i];
            double speed = pos_speed[position[i]];
            double time = distance / speed;
            if (stk.empty() || time > stk.top()) {
                stk.push(time);
            }
        }
        return stk.size();
    }
};
