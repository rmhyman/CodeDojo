/*
Main program to work on C++11 syntax * main.cpp
 *
 *  Created on: Dec 21, 2013
 *      Author: rmhyman
 */

#include<iostream>
#include<array>
#include<algorithm>
using namespace std;


int main ()
{
	array<int,5>a = {1,5,-3,2000,30};

	for(auto i:a) {
		cout<< i << endl;
	}

	std::sort(a.begin(),a.end(), [] (int x, int y) -> bool { return std::abs(x) < std::abs(y);});

	cout << "a array after sort algorithm" << endl;
	for(auto & i : a){
		cout << i << endl;
	}
	cout << "type of a is " << typeid(a).name() << endl;

	return 0;
}





