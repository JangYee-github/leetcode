
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
    int size = nums.size() - 1;
    int split_int = nums[size];
    vector<int> nums1 (begin(nums), begin(nums) + split_int);
    vector<int> nums2 (begin(nums) + split_int, begin(nums) + size);
    for ( auto i = nums1.begin(); i < nums1.end(); i++) {
        // cout << *i << " ";
    }
    // cout << endl;
    for ( auto i = nums2.begin(); i < nums2.end(); i++) {
        // cout << *i << " ";
    }
    // cout << endl;
    Solution s;
    cout << "------------------" << endl;
    double res = s.findMedianSortedArrays(nums1, nums2);
    cout << res << endl;
    cout << "------------------" << endl;
	return 0;
}
