
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>


#include "solution.cpp"

int main(int argc, char **argv) {
    string str;
    cin >> str;
    Solution s;
    bool res = s.isValid(str);
    cout << res << endl;
}
