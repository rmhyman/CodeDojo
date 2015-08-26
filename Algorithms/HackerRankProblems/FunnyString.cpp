/*
 * FunnyString.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: rmhyman
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


string FunnyString(const string& s){
    int size = s.size();
    int i,j;
    for(i = 1,j = size-2; i < size, j > 0; ++i,--j){
        int sval = std::abs(s[i] - s[i-1]);
        int rval = std::abs(s[j] - s[j+1]);
        if(sval != rval){
            return "Not Funny";
        }
    }

    return "Funny";
}
int main() {
    int  t;
    cin >> t;
    string s;
    while(t--){
        cin >> s;
        cout << FunnyString(s) << endl;
    }
    return 0;
}



