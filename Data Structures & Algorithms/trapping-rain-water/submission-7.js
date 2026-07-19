class Solution {
    /**
     * @param {number[]} height
     * @return {number}
     */
    trap(height) {
        if (!height.length) return 0;
        let left = 0, right = height.length - 1;
        let leftMax = height[left], rightMax = height[right];
        let trapArea = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                ++left;
                leftMax = Math.max(leftMax, height[left]);
                trapArea += leftMax - height[left];
            } else {
                --right;
                rightMax = Math.max(rightMax, height[right]);
                trapArea += rightMax - height[right];
            }
        }
        return trapArea;
    }
}
