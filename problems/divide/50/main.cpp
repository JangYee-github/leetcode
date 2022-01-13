
#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>



#include "solution.cpp"

int main(int argc, char **argv) {
	vector<int> nums;
	double x;
	int n;
	cin >> x >> n;
    Solution s;
    double res = s.myPow(x, n);
    cout << res << endl;
	return 0;
}
