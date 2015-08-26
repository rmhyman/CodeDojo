/*
 * Staircase.cpp
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

vector<string> MakeStairs(const int height){
    vector<string> v(height,string(height,'#'));
    for(int i = 0; i < height; ++i){
        if(i == 0){
            continue;
        }
        else{
            v[height - i - 1].replace(0,i,i,' ');
        }
    }
    return v;
}
int main() {
    int n;
    cin >> n;
    vector<string> stairs = MakeStairs(n);
    for(auto & s : stairs){
        cout << s << endl;
    }
    return 0;
}




