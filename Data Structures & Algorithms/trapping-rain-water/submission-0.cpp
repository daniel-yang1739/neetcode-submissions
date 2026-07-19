class Solution {
public:
    int trap(vector<int>& height) {
        int trap_area = 0;
        for (int i = 0; i < height.size(); ++i) {
            int max_LHeight = 0, max_RHeight = 0;
            for (int h = 0; h < i; ++h) {
                max_LHeight = max(max_LHeight, height[h]);
            }
            for (int h = i + 1; h < height.size(); ++h) {
                max_RHeight = max(max_RHeight, height[h]);
            }
            int trap_height = min(max_LHeight, max_RHeight);
            if (height[i] < trap_height) {
                trap_area += trap_height - height[i];
            }
        }
        return trap_area;
    }
};
