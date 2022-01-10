
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
    Solution s;
    vector<vector<int>> res = s.threeSum(nums);
    for (auto i = res.begin(); i < res.end(); i++) {
        for (auto j = i->begin(); j < i->end(); j++) {
            cout << *j << " ";
        }
        cout << endl;
    }
	return 0;
}
