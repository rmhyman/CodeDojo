/*
 * SherlockSquares.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: rmhyman
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using BigInt = unsigned long long int;
using CBigInt = const unsigned long long int;
int NumOfPerfectSquares(CBigInt min, CBigInt max){
    double lower_bound_ = std::sqrt(static_cast<double>(min));
    lower_bound_ = std::floor(lower_bound_);
    BigInt lower_bound = static_cast<BigInt>(lower_bound_);
    double upper_bound_ = std::sqrt(static_cast<double>(max));
    upper_bound_ = std::floor(upper_bound_);
    BigInt upper_bound = static_cast<BigInt>(upper_bound_);

    BigInt perfect_square = lower_bound * lower_bound;
    int num_squares = 0;
    while(perfect_square <= max){
        if(perfect_square >= min && perfect_square <= max){
            ++num_squares;
        }
        ++lower_bound;
        perfect_square = lower_bound * lower_bound;
    }

    return num_squares;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    int min,max;
    cin >> t;
    while(t--){
        cin>>min>>max;
        cout << NumOfPerfectSquares(min,max) << endl;
    }
    return 0;
}




