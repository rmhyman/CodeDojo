/*
 * ChocolateFeast.cpp
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
int ComputeNumChocolates(const int cash, const int cost, const int wrappers_needed){
    int chocolate_bought = cash / cost;
    int num_wrappers = chocolate_bought;
    int extra_chocolate = 0;
    while(num_wrappers >= wrappers_needed){
        ++extra_chocolate;
        ++num_wrappers;
        num_wrappers -= wrappers_needed;
    }



    return chocolate_bought + extra_chocolate;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,n,c,m;
    cin>>t;
    while(t--){
        cin>>n>>c>>m;
        cout<<ComputeNumChocolates(n,c,m)<<endl;
    }
    return 0;
}




