/*
 * main.cpp
 *
 *  Created on: Nov 8, 2014
 *      Author: rmhyman
 */

#include<iostream>
#include<forward_list>
#include "linked_lists.h"
using namespace std;
int main () {


	std::forward_list<unsigned>&& l1 (InsertWithEmplace());

	std::forward_list<unsigned>&& l2 (InsertWithEmplace());

	auto printout = [&](bool first) -> void {
		for(auto & number : (first)? l1 : l2){
				cout << number << " ";
			}
		cout << endl;
	};

	l1.remove_if([](int n) {return n > 10;});
	l2.remove_if([](int n) {return n > 5;});
	cout << "l1 after removing elements greater than 10: ";
	printout(true);
	cout << "l2 after removing elements greater than 5: ";
		printout(false);
	cout << "l2 after splice_after call: ";
	l2.splice_after(l2.before_begin(),l1);
		printout(false);
		cout << "l1 after splice_after call: ";
		printout(true);
	l2.unique();
	cout << "l2 after unique call on a unsorted linked list:";
	printout(false);

	cout << "l2 after sorted call: ";
	l2.sort();
	printout(false);l2.unique();
	cout << "l2 after unique call on a sorted linked list:";
	printout(false);
	cout << "l1 after swap call: ";
	std::swap(l1,l2);
	printout(true);
	cout << "l1 after reverse call:";
	l1.reverse();
		printout(true);
	cout << "Complete" << endl;

	return 0;
}


