
#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

#include "solution.cpp"

int main(int argc, char **argv) {
	vector<int> nums;
    int split, num;
	while ((cin >> num)) {
		nums.push_back(num);
	}
	split = nums.back();
    vector<int> g(nums.begin(), nums.begin() + split);
    vector<int> s(nums.begin() + split, nums.begin() + (nums.size() - 1));
    
    // for (auto i = g.begin(); i< g.end(); i++) {
    //     cout << *i << endl;
    // }
    // cout << "---------" << endl;
    // for (auto i = s.begin(); i< s.end(); i++) {
    //     cout << *i << endl;
    // }
    // cout << "---------" << endl;
    Solution solution;
    int res = solution.findContentChildren(g, s);
    cout << res << endl;
	return 0;
}
