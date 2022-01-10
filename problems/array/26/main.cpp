
#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>


#include "solution.cpp"

int main(int argc, char **argv) {
	vector<int> nums;
	int num;
	while ((cin >> num)) {
		nums.push_back(num);
	}
    Solution s;
    int res_len = s.removeDuplicates(nums);
    for (int i = 0; i < res_len; i++) {
        cout << nums[i] << endl;
    }
	return 0;
}
