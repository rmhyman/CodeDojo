/*
 * linked_lists.cpp
 *
 *  Created on: Nov 8, 2014
 *      Author: rmhyman
 */


#include<forward_list>
#include "linked_lists.h"
using namespace std;

void InsertWithPush(std::forward_list<unsigned>& l1){
for(auto i = 0; i < 10000000; ++i){

		l1.push_front(i);
	}
}

std::forward_list<unsigned> InsertWithEmplace(){
	std::forward_list<unsigned> tmp;
for(auto i = 0; i < 100; ++i){

		tmp.emplace_front(i);
	}
	return tmp;
}
