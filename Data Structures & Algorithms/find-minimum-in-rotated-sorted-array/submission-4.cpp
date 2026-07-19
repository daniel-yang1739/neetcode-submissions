class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            // because each element is UNIQUE, so 
            // `nums[mid]` MUST not equal to `nums[right]`
            if (nums[mid] < nums[right]) {
                // mid is in the right increasing slot,
                // the minimum value MUST at left
                right = mid;
            } else {
                // mid is in the left increasing slot,
                // the minimum value MUST at right
                left = mid + 1;
            }
        }
        return nums[left];
    }
};
