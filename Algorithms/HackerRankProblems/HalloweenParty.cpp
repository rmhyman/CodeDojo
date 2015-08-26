/*
 * HalloweenParty.cpp
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
long long int MaxChocolatePieces(const long long int num_cuts){
    if(num_cuts % 2 == 0 ){
        long long int split = num_cuts / 2;
        return split * split;
    }
    else {
        long long int split = num_cuts / 2;
        long long int remainder = num_cuts - split;
        return split * remainder;
    }

    return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num_test_cases = 0;
    long long int num_cuts = 0;
    cin >> num_test_cases;

    for(int i = 0; i < num_test_cases; ++i){
        cin >> num_cuts;
        cout << MaxChocolatePieces(num_cuts) << endl;
    }
    return 0;
}




