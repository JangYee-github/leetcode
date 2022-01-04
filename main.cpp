/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  leetcode main.cpp
 *
 *        Version:  1.0
 *        Created:  01/04/2022 10:22:09 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  JangYee
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "JangYee/1.cpp"
#include "office/1.cpp"

using namespace std;

vector<int> args2Vector(const char * args) {
    
}

void oneJangYeeTest(vector<int> nums, int target) {
    JangYee::Solution solution;
    cout << solution.twoSum(vector<int> nums, int target) << endl;
}

void oneLeetcodeTest(const char * args) {
    JangYee::Solution solution;
    cout << solution.twoSum(vector<int> nums, int target) << endl;
}




int main(int argc, char *argv[]) {
    
    return 0;






    /* 
    int i;
    cout << "your args num is " << (argc-1) << " \n";
    for (i=1; i<argc; i++) {
        cout << i<< ": " << argv[i] << endl;
    }

    JangYee::People p;
    p.initPeople("JangYee", 26);
    p.showPeople();

    leetcode::People p1;
    p1.initPeople("leetcode", 10);
    p1.showPeople();
    */
}
