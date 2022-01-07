
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

    }
};


int main(int argc, char **argv) {
	vector<int> nums;
	int num, len, target;
	while ((cin >> num)) {
		nums.push_back(num);
	}
	target = nums.back();
	nums.pop_back();
	len = nums.size();
	for (auto i = nums.begin(); i < nums.end(); i++) {
		cout << *i << endl;	
	}
	cout << "target is : " << target << endl;
	return 0;
}
