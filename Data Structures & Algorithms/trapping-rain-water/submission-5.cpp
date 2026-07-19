class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int left = 0, right = height.size() - 1;
        int left_max = height[left], right_max = height[right];
        int trap_area = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                ++left;
                left_max = max(left_max, height[left]);
                trap_area += left_max - height[left];
            } else {
                --right;
                right_max = max(right_max, height[right]);
                trap_area += right_max - height[right];
            }
        }
        return trap_area;
    }
};
