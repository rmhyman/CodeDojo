/*
 * AndProduct.cpp
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

BigInt PerformBitWiseAnd(BigInt a, BigInt b){
    if(a == b){
        return a & b;
    }
    else{

        BigInt tmp = a + 1;
        BigInt ans = a;
        while(tmp < b){
            ++tmp;
            ans &= tmp;
        }
        ans &= b;
        return ans;
    }
    return 0;
}
int main() {
    int t;
    unsigned a,b;
    cin >>t;
    while(t--){
        cin >> a >> b;
        cout <<PerformBitWiseAnd(a,b) << endl;;
    }
    return 0;
}




