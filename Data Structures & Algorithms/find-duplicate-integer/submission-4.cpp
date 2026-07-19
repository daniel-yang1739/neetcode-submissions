class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }
        // Floyd's Cycle Detection
        int slow2 = nums[0];
        while (true) {
            if (slow == slow2) break;
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow2;
    }
};
