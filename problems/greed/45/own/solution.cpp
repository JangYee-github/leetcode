class Solution {
public:
    int jump(vector<int>& nums) {
		int size = nums.size();
        if (size <= 1)
            return 0;
        int end = size - 1;
		int far_limit = nums[0], far_i = 0;
        int i, j, counter = 0;
		for (i = 0; i < size; i++) {
			counter++;
			if (far_limit < i)
				return -1;
			if (far_limit >= end)
				break;
			for (j = i; j <= nums[i] + i; j++) {
				if (far_limit  < (j + nums[j])) {
					far_limit = j + nums[j];
					far_i = j;
				}
			}
			if (i > far_i)
				return -2;
			i = far_i - 1;
			
		}
		return counter;
    }
};
