
#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

#include "solution.cpp"

int main(int argc, char **argv) {
	vector<int> nums;
    int num;
	while ((cin >> num)) {
		nums.push_back(num);
	}
    Solution solution;
    bool res = solution.canJump(nums);
    cout << res << endl;
	return 0;
}
