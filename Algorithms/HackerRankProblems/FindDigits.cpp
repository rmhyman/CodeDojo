/*
 * FindDigits.cpp
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
bool DigitIsDivisible(const char c, const long long int num){
    string s;
    s = c;
    int tmp = std::stoi(s);
    if(tmp == 0){
        return false;
    }

    return num % tmp == 0;
}

int CountDivisibleDigits(long long int val){
    string s = std::to_string(val);
    int count = 0;
    for(int i = 0; i < s.size(); ++i){
        if(DigitIsDivisible(s[i], val)){
            ++count;
        }
    }
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num_test_cases = 0;
    long long int input = 0;
    cin >> num_test_cases;
    for(int i = 0; i < num_test_cases; ++i){
        cin >> input;
        cout << CountDivisibleDigits(input) << endl;
    }
    return 0;
}




