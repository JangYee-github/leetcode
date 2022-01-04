/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  test demo
 *
 *        Version:  1.0
 *        Created:  01/05/2022 12:47:54 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {
    freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    char buf[1024];
    while (cin.getline(buf, 1024)) {
        cout << buf;
    }
    return 0;
}
