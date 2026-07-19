class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        unordered_map<int, int> numCount;
        for (int num : hand) {
            ++numCount[num];
        }
        sort(hand.begin(), hand.end());
        for (int num : hand) {
            if (numCount[num] == 0) {
                continue;
            }
            for (int i = num; i < num + groupSize; ++i) {
                if (numCount.count(i) == 0) {
                    return false;
                }
                --numCount[i];
            }
        }
        return true;
    }
};
