/*
 * =====================================================================================
 *
 *       Filename:  tclass.cpp
 *
 *    Description:  test class
 *
 *        Version:  1.0
 *        Created:  01/04/2022 11:19:15 PM
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
#include <string.h>

namespace JangYee {
    class People {
        public:
            char name[100];
            int age;
    
            void initPeople(const char * p_name, int p_age) {
                strcpy(name, p_name);
                age = p_age;
            }
    
            void showPeople() {
                std::cout << "My name is " << name << ", my age is " << age << std::endl;
            }
    };
}

