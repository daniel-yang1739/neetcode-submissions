class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() < groupSize) {
            return false;
        }
        unordered_map<int, int> numCount;
        for (int num : hand) {
            ++numCount[num];
        }
        unordered_map<int, int> used;
        sort(hand.begin(), hand.end());
        for (int num : hand) {
            if (used[num] == numCount[num]) {
                continue;
            }
            int checkNum = num;
            for (int i = 0; i < groupSize; ++i) {
                if (
                    !numCount.count(checkNum) ||
                    used[checkNum] > numCount[checkNum]
                ) {
                    return false;
                }
                ++used[checkNum];
                ++checkNum;
            }
        }
        return true;
    }
};
