class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        int m = nums1.size(), n = nums2.size();
        int total = m + n;
        int left = 0, right = m;
        while (left <= right) {
            int p1 = left + (right - left) / 2;
            int p2 = (total + 1) / 2 - p1;
            
            int maxLeft1 = p1 > 0 ? nums1[p1 - 1] : INT_MIN;
            int minRight1 = p1 < m ? nums1[p1] : INT_MAX;
            int maxLeft2 = p2 > 0 ? nums2[p2 - 1] : INT_MIN;
            int minRight2 = p2 < n ?  nums2[p2] : INT_MAX;

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if (total % 2 == 1) {
                    return max(maxLeft1, maxLeft2);
                } else {
                    return (
                        max(maxLeft1, maxLeft2) + 
                        min(minRight1, minRight2)
                    ) / 2.0;
                }
            } else if (maxLeft1 > minRight2) {
                right = p1 - 1;
            } else {
                left = p1 + 1;
            }
        }
        return 0;
    }
};
