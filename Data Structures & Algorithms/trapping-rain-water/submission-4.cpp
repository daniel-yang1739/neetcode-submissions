class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int left = 0, right = height.size() - 1;
        int leftMax = height[left], rightMax = height[right];
        int trap_area = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                ++left;
                leftMax = max(leftMax, height[left]);
                trap_area += leftMax - height[left];
            } else {
                --right;
                rightMax = max(rightMax, height[right]);
                trap_area += rightMax - height[right];
            }
        }
        return trap_area;
    }
};
