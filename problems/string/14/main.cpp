
#include <iostream>
using namespace std;
#include <string>
#include <vector>


#include "solution.cpp"

int main(int argc, char **argv) {
	vector<string> strs;
    string str;
	int num;
	while ((cin >> str)) {
        cout << str << endl;
		strs.push_back(str);
	}
    Solution s;
    string restr = s.longestCommonPrefix(strs);
    cout << restr << endl;
}
