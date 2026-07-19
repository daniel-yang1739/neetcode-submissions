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
        for (int i = 0; i < h_size; ++i) {
            trap_area += (
                min(max_LHeight[i], max_RHeight[i]) - height[i]);
        }
        return trap_area;
    }
};
