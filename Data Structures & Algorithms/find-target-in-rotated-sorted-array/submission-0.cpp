class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        // check target at right slot or not
        bool is_right = target <= nums[right];
        while (left < right) {
            int mid = left + (right - left) / 2;
            cout << left << " " << right << endl;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > nums[right]) {
                // the mid is now in left slot
                if (target > nums[mid] || target < nums[left]) {
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