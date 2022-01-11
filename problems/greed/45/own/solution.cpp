class Solution {
public:
    int jump(vector<int>& nums) {
		int size = nums.size();
		int far_limit = 0, far_i;
		int i, j, counter = -1;
		for (i = 0; i < size; i++) {
			cout << i << endl;
			if (far_limit < i)
				return -1;
			if (far_limit > size)
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
			counter++;
			
		}
		return counter + 1;
    }
};
