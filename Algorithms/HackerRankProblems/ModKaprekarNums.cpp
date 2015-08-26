/*
 * ModKaprekarNums.cpp
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

bool IsKaprekarNum(const long long int num){
    long long int tmp = num * num;
    string s = std::to_string(tmp);
    int size = s.size();
    if(size > 1){
     int mid = size / 2;
    string r_str = s.substr(mid);
    string l_str = s.substr(0,mid);
    int right = stoi(r_str);
    int left = stoi(l_str);
    int sum = right + left;
    return sum == num;
    }
    else if(num == 1){
        return true;
    }

    return false;

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int p;
    int q;
    cin >> p;
    cin >> q;
    vector<int> kp_nums;
    kp_nums.reserve(100);
    for(int i = p; i <= q; ++i){
        if(IsKaprekarNum(i)){
            kp_nums.push_back(i);
        }
    }
    if(!kp_nums.empty()){
        for(auto & num : kp_nums){
            cout << num << ' ';
        }
    }
    else{
        cout << "INVALID RANGE" << endl;
    }
    return 0;
}




