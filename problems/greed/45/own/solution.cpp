class Solution {
public:
    int jump(vector<int>& nums) {
		int size = nums.size();
		int far_limit = 0, far_i;
		int i, j, counter = 0;
		for (i = 0; i < size; i++) {
			if (far_limit < i)
				return 0;
			if (far_limit > size)
				break;
			for (j = i; j <= nums[i] + i; j++) {
				if (far_limit  < (j + nums[j])) {
					far_limit = j + nums[j];
					far_i = j;
				}
			}
			if (i < far_i)
				return 0;
			i = far_i - 1;
			counter++;
			
		}
		return counter;
    }
};
