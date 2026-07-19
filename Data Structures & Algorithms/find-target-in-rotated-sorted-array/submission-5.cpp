class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > nums[right]) {
                // the mid is now in left slot
                if (nums[mid] < target || target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            } else {
                // the mid is now in right slot
                if (nums[mid] > target || target > nums[right]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
        }
        return nums[right] == target ? right : -1;
    }
};