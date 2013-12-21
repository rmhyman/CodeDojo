/*
This program will illustrate the usage of some of the C++11 new syntax
 * main.cpp
 *
 *  Created on: Dec 20, 2013
 *      Author: rmhyman
 */

#include<iostream>
#include<array>
using namespace std;

int main ()
{
	array<int, 5> x = {1,2,3,4,5};

	for(auto i : x){
		std::cout << i << std::endl;
	}

	return 0;
}



