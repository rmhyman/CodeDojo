/*
 * LoveLetterMystery.cpp
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

int CalcNumOps(const char first, const char second){
    int num = first;
    int num2 = second;

    return std::abs(first - second);
}
int NumOpsToPalindrome(const string& s){
    auto pos1 = s.begin();
    auto pos2 = s.end() - 1;
    int dist1 = std::distance(s.begin(),pos1);
    int dist2 = std::distance(s.begin(),pos2);
    int num_ops = 0;
    while(dist2 > dist1){
        num_ops += CalcNumOps(*pos1,*pos2);
        ++pos1;
        --pos2;
        dist1 = std::distance(s.begin(),pos1);
        dist2 = std::distance(s.begin(),pos2);
    }
    return num_ops;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num_test_cases = 0;
    cin >> num_test_cases;
    string input;
    for(int i = 0; i < num_test_cases; ++i){
        cin  >> input;
        cout << NumOpsToPalindrome(input) << endl;
    }
    return 0;
}




