
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
    int max_area = s.maxArea(nums);
    cout << max_area << endl;
	return 0;
}
