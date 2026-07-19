class Solution {
public:
    int timeSpendToEat(vector<int>& piles, int k) {
        int time = 0;
        for (int p : piles) {
            time += (p - 1) / k + 1;  // ceil
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1000000000;
        while (left != right) {
            int mid = left + (right - left) / 2;
            int spend = timeSpendToEat(piles, mid);
            if (spend > h) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return right;
    }
};
