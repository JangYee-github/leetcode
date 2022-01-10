
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>


#include "solution.cpp"

int main(int argc, char **argv) {
    string str;
    cin >> str;
    Solution s;
    int res = s.lengthOfLongestSubstring(str);
    cout << res << endl;
}
