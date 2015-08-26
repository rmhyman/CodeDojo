/*
 * TaumBday.cpp
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
using ConstBigInt = const unsigned long long int;
using BigInt = unsigned long long int;
BigInt ComputeConversionRate(ConstBigInt cost_of_bgifts,  ConstBigInt cost_of_wgifts, ConstBigInt conversion_cost){

    BigInt lower_cost = 0;
    BigInt bconv_rate = cost_of_bgifts + conversion_cost;
     BigInt wconv_rate = cost_of_wgifts + conversion_cost;
    if(bconv_rate < cost_of_wgifts )
        lower_cost = bconv_rate;
    else if( wconv_rate < cost_of_bgifts)
        lower_cost = wconv_rate;

        return lower_cost;
}

BigInt CalcGiftCost(ConstBigInt num_bgifts, ConstBigInt num_wgifts, ConstBigInt cost_of_bgifts, ConstBigInt cost_of_wgifts, ConstBigInt conv_cost){

    BigInt conversion_rate = ComputeConversionRate(cost_of_bgifts,cost_of_wgifts,conv_cost);
    BigInt opt_wcost = cost_of_wgifts;
    BigInt opt_bcost = cost_of_bgifts;

    if(((conversion_rate <= cost_of_bgifts) && (conversion_rate >= cost_of_wgifts))  || ((conversion_rate <= cost_of_wgifts) && (conversion_rate >= cost_of_bgifts)) ){
        if(cost_of_bgifts < cost_of_wgifts){
            opt_wcost = conversion_rate;
        }
        else{
            opt_bcost = conversion_rate;
        }
    }

    //cout << opt_bcost << " " << opt_wcost << endl;

    return ((num_bgifts * opt_bcost) + (num_wgifts * opt_wcost));
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    BigInt b,w,x,y,z;
    cin >> t;
    while(t--){
        cin >> b >> w;
        cin >>x >>y>>z;
        cout << CalcGiftCost(b,w,x,y,z) << endl;
    }
    return 0;
}




