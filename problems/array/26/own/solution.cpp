class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int nums_size = nums.size();
        if (nums_size == 0) {
            return 0;
        }
        int fast, slow;
        for (fast = 1, slow = 0; fast < nums_size; ) {
            if (nums[fast] == nums[slow]) {
                fast++;
                continue;
            }
            slow++;
            nums[slow] = nums[fast];
            fast++;
        }
        return slow + 1;
    }
};
