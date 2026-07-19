class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int l = left, r = right - 1;
        while (l <= r) { 
            while (l <= r && nums[l] < pivot) ++l;
            while (l <= r && nums[r] >= pivot) --r;
            if (l < r) swap(nums[l], nums[r]);
        }
        swap(nums[right], nums[l]);
        return l;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        int left = 0, right = nums.size() - 1;
        while (true) {
            int idx = partition(nums, left, right);
            if (idx < size - k) {
                left = idx + 1;
            } else if (idx > size - k) {
                right = idx - 1;
            } else {
                return nums[idx];
            }
        }
        return 0;
    }
};
