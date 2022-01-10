
#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>


#include "solution.cpp"

int main(int argc, char **argv) {
	vector<int> nums;
	int num, len, target;
	while ((cin >> num)) {
		nums.push_back(num);
	}
	target = nums.back();
	nums.pop_back();
	len = nums.size();
    Solution s;
    vector<int> res = s.twoSum(nums, target);
    for (auto i = res.begin(); i< res.end(); i++) {
        cout << *i << endl;
    }
	return 0;
}
