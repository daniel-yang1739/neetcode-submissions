class Solution {
public:
    int timeSpendToEat(vector<int>& piles, int k) {
        int time = 0;
        for (int p : piles) {
            time += (p + k - 1) / k;  // ceil
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
