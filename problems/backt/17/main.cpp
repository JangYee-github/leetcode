
#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>


#include "solution.cpp"

int main(int argc, char **argv) {
	string ds;
	cin >> ds;
	Solution solution;
	vector<string> res = solution.letterCombinations(ds);
	for (auto i : res)
		cout << i << endl;
	return 0;
}
