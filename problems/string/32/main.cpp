
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <stack>
#include <algorithm>


#include "solution.cpp"

int main(int argc, char **argv) {
    string str;
    cin >> str;
    Solution s;
    int res = s.longestValidParentheses(str);
    cout << res << endl;
}
