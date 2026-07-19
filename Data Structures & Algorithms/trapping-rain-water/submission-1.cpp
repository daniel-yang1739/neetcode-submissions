class Solution {
public:
    int trap(vector<int>& height) {
        int h_size = height.size();
        vector<int> max_LHeight(h_size), max_RHeight(h_size);
        max_LHeight[0] = height[0];
        for (int i = 1; i < h_size; ++i) {
            max_LHeight[i] = max(max_LHeight[i - 1], height[i]);
        }
        max_RHeight[h_size - 1] = height[h_size - 1];
        for (int i = h_size - 2; i >= 0; --i) {
            max_RHeight[i] = max(max_RHeight[i + 1], height[i]);
        }
        int trap_area = 0;
        for (int i = 1; i < h_size - 1; ++i) {
            int trap_height = min(max_LHeight[i - 1], max_RHeight[i + 1]);
            if (height[i] < trap_height) {
                trap_area += trap_height - height[i];
            }
        }
        return trap_area;
    }
};
