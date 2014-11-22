/*
 * mult_of_3_5.cpp
 *
 *  Created on: Nov 7, 2014
 *      Author: rmhyman
 */
//If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6
//and 9. The sum of these multiples is 23.
//Find the sum of all the multiples of 3 or 5 below 1000.
#include<iostream>
using namespace std;

int main() {

	auto sum = 0;
	for(auto number = 0; number < 1000; ++number){
		if(number % 3 == 0 or number % 5 == 0){
			sum+=number;
		}
	}

	cout << " Sum of multiples of 3 or 5 equals " << sum << endl;
	return 0;
}


