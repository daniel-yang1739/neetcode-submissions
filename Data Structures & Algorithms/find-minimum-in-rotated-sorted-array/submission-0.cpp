class Solution {
public:
    int findMin(vector<int> &nums) {
        int res = nums[0];
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            if (nums[left] < nums[right]) {
                // the array from left to right
                // had been sorted.
                res = min(res, nums[left]);
                break;
            }
            int mid = left + (right - left) / 2;
            res = min(res, nums[mid]);
            if (nums[mid] >= nums[left]) {
                // mid is in left increasing slot,
                // so the minimum MAY at right.
                left = mid + 1;
            } else {
                // mid is in the right increasing slot,
                // so the minimum MUST at left.
                right = mid - 1;
            }
        }
        return res;
    }
};
