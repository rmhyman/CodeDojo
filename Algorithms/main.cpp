/*
 * main.cpp
 *
 *  Created on: Nov 15, 2014
 *      Author: rmhyman
 */

#include<iostream>
#include<algorithm>
#include<random>
#include<vector>
using namespace std;

int main () {

	auto printout = [&](const auto & container) -> void {
			for(auto & number : container){
					cout << number << " ";
				}
			cout << endl;
		};

	std::vector<unsigned> nums = {1,3,4, 5,7};
	nums.reserve(20);
	cout << "Capacity of nums vector equals " << nums.capacity() << endl;
	std::iota(nums.begin(),nums.end(),1);
	nums.shrink_to_fit();
	cout << "Capacity of nums vector after shrink_to_fit() equals " << nums.capacity() << endl;

	std::vector<unsigned> values(20);
	std::iota(values.begin(),values.end(),1);

	cout << "nums array initialized using initializer list" << endl;
	printout(nums);
	cout << "Values array after initilization using the std::iota algorithm" << endl;
	printout(values);

	cout << "Values array shuffled twice" << endl;
	std::random_shuffle(values.begin(),values.end());
	printout(values);
	std::random_shuffle(values.begin(),values.end());
	printout(values);

	std::vector<unsigned> random(25);
	std::random_device r;
	std::uniform_int_distribution<unsigned> distro(1,25);
	auto ran_gen = [&](auto& element){ element = distro(r);};
	std::for_each(random.begin(),random.end(),ran_gen);
	std::vector<unsigned> random2(25);
	std::iota(random2.begin(),random2.end(),distro(r));
	cout << "Random array generated using generic lambda that sets each element using the uniform_int_distribution and the for_each algorithm" << endl;
	printout(random);
	cout << "Random array generated using the uniform_int_distribution as a predicate for the iota function" << endl;
	printout(random2);


	std::vector<unsigned> copy(values);

	std::vector<unsigned> copy2 (values.begin(),std::mismatch(values.begin(), values.end(), copy.begin(),copy.end()).first);

	cout << "Mismatch array after use of the mismatch algorithm on copy of same array" << endl;
	printout(copy2);
	std::fill(copy2.begin(),copy2.end(),0);
	std::generate(copy2.begin(),copy2.end(),[&]{return distro(r);});
	cout << "Array after applying std::generate alg with the distro function" << endl;
	printout(copy2);
	cout << "Next permutation equals " << endl;
	std::next_permutation(copy2.begin(),copy2.end());
	printout(copy2);
	return 0;
}



