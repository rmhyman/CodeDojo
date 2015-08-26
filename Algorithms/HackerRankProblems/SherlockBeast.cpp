/*
 * SherlockBeast.cpp
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
string CalcLargestDecentNum(const int num_digits){
    if(num_digits < 3 || num_digits == 4){
        return "-1";
    }
    else if(num_digits % 3 == 0){
        return string(num_digits,'5');
    }
    else{
        int max = num_digits;
        int remainder = 0;
        while(max >= 3){
         if((max % 3 ==0) && (remainder % 5 == 0)){
           string threes(remainder,'3');
           string fives(max,'5');
            return fives + threes;
         }
            --max;
            ++remainder;
        }

        if((num_digits % 5) == 0){
            return string(num_digits,'3');
        }
    }
    return "-1";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << CalcLargestDecentNum(n) << endl;
    }
    return 0;
}




