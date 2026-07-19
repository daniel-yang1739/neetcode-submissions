class Solution {
public:
    int timeSpendToEat(vector<int>& piles, int k) {
        int time = 0;
        for (double p : piles) {
            time += ceil(p / k);
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1000000000;
        while (left != right) {
            int k = (left + right) / 2;
            int spend = timeSpendToEat(piles, k);
            if (spend > h) {
                left = k + 1;
            } else {
                right = k;
            }
        }
        return right;
    }
};
