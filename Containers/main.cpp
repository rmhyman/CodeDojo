/*
 * main.cpp
 *
 *  Created on: Nov 8, 2014
 *      Author: rmhyman
 */

#include<iostream>
#include<forward_list>
#include<queue>
#include<deque>
#include<random>
#include<unordered_set>
#include<algorithm>
#include "linked_lists.h"
using namespace std;
int main () {


	std::forward_list<unsigned>&& l1 (InsertWithEmplace());

	std::forward_list<unsigned> l2 (10000000);

	std::iota(l2.begin(),l2.end(),1);

	auto printout = [&](const auto & container) -> void {
		for(auto & number : container){
				cout << number << " ";
			}
		cout << endl;
	};

	l1.remove_if([](int n) {return n > 10;});
	l2.remove_if([](int n) {return n > 5;});
	cout << "l1 after removing elements greater than 10: ";
	printout(l1);
	cout << "l2 after removing elements greater than 5: ";
		printout(l2);
	cout << "l2 after splice_after call: ";
	l2.splice_after(l2.before_begin(),l1);
		printout(l2);
		cout << "l1 after splice_after call: ";
		printout(l1);
	l2.unique();
	cout << "l2 after unique call on a unsorted linked list:";
	printout(l2);

	cout << "l2 after sorted call: ";
	l2.sort();
	printout(l2);
	l2.unique();
	cout << "l2 after unique call on a sorted linked list:";
	printout(l2);
	cout << "l1 after swap call: ";
	std::swap(l1,l2);
	printout(l1);
	cout << "l1 after reverse call:";
	l1.reverse();
		printout(l1);
	cout << "Linked List functions Complete" << endl;

	cout << "Now implementing Priority Queues Exercising the following member functions:\nemplace()\ntop()\npop()" << endl;
	cout << "Used std::random_device and std::uniform_int_distribution to populate the queue"<< endl;
	std::priority_queue<unsigned> queue;
	std::deque<unsigned> deque_tmp;
	std::random_device num_gen;
	std::uniform_int_distribution<unsigned> dis(1,100000);

	for(auto i = 0; i < 20; ++i){
		queue.emplace(dis(num_gen));
	}

	cout << "Can't use new for loop syntax with adaptor containers like priority_queue" << endl;
	for(auto num = 0; num < 20; ++num ){
		cout << queue.top() << " ";
		deque_tmp.emplace(deque_tmp.begin(),queue.top());
		queue.pop();
	}
	cout << endl;

	cout << "Printing Deque values" << endl;
	printout(deque_tmp);
	cout<<endl;
	std::mt19937 g;
	cout << "Shuffling the deque using std::shuffle()" << endl;
	std::shuffle(deque_tmp.begin(), deque_tmp.end(),g);
	printout(deque_tmp);
	cout << endl;

	cout << "Converting the deque into a heap using std::make_heap()" << endl;
	std::make_heap(deque_tmp.begin(),deque_tmp.end());
	printout(deque_tmp);

	cout << "Now looking at the new unordered_set container" << endl;

	auto HashFunc = [&] (unsigned const & x) {return x % 8;};
	std::unordered_set<unsigned, decltype(HashFunc)> hash_table(2,HashFunc);
	for(auto i = 1; i < 33; ++i){
		hash_table.emplace(i);
	}

	cout << "bucket_count is " << hash_table.bucket_count() << endl;
	cout << "bucket size of bucket 4 is " << hash_table.bucket_size(4) << endl;

	auto printKey = [&] (unsigned bucket) -> void {
		for(auto  i = hash_table.begin(bucket); i != hash_table.end(bucket); ++i){
			cout << *i << " ";
		}
		cout << endl;
	};

	cout << "Elements in bucket 4 are :";
	printKey(4);

	cout << "Current load factor is " << hash_table.load_factor() << endl;

	cout << "Performing a rehash on the hash table and increasing the load_factor to 4" << endl;
	hash_table.max_load_factor(4);
	hash_table.rehash(8);

	cout << "bucket_count is " << hash_table.bucket_count() << endl;
	cout << "bucket size of bucket 4 is " << hash_table.bucket_size(4) << endl;
	cout << "Current load factor is " << hash_table.load_factor() << endl;

	return 0;
}


