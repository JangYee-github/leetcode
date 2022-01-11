class Solution {
public:
    bool canJump(vector<int>& nums) {
		int size = nums.size();
		int far_limit = 0;
		for ( int i = 0; i < size; i++) {
			if (far_limit > size)
				return true;
			if (far_limit < i)
				return false;
			far_limit = far_limit > (i + nums[i])? far_limit : (i + nums[i]);
		}
		return true;
    }
};
