/*
 * CutSticks.cpp
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

vector<int> GetSticks(const int num_sticks){
    int val = 0;
    vector<int> sticks;
    sticks.reserve(num_sticks);
    for(int i = 0; i < num_sticks; ++i){
        cin >> val;
        sticks.push_back(val);
    }
    return sticks;
}
void CutSticks(const vector<int>& v){
    vector<int> sticks(v);
    std::sort(sticks.begin(),sticks.end());
    while(!sticks.empty()){
    int min_value = sticks[0];
    std::transform(sticks.begin(),sticks.end(),sticks.begin(),[&min_value](const int val) {return val - min_value;});
    cout << sticks.size() << endl;
    sticks.erase(std::remove_if(sticks.begin(),sticks.end(),[](const int val) {return val == 0;}),sticks.end());
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num_sticks = 0;
    cin >> num_sticks;
    vector<int> sticks = GetSticks(num_sticks);
    CutSticks(sticks);
    return 0;
}




