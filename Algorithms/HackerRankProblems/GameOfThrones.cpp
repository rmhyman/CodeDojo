/*
 * GameOfThrones.cpp
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
#include <unordered_map>
using namespace std;


bool HasAPalindrome(const string& s){
    unordered_map<char,int> ht;
    for(auto & c : s){
        ++ht[c];
    }
    int start = 'a';
    int end = 'z';
    ++end;
    int num_odd_more_than_one = 0;
    int num_equal_one = 0;
    int even = 0;
    for(int i = start; i < end; ++i){
        if(ht[i] == 1){
            ++num_equal_one;
        }
        else if(ht[i] % 2 == 1){
            ++num_odd_more_than_one;
        }
        else if (ht[i] != 0){
            //cout << i << endl;
            ++even;
        }


    }
    if((num_equal_one > 0 && num_odd_more_than_one > 0)){
            return false;
     }
    else if(num_odd_more_than_one > 1){
        return false;
    }
    else if(even == 0){
        return false;
    }
   //cout << "start equals " << start << endl;
    return true;
}

int main() {

    string s;
    cin>>s;

    bool flag = HasAPalindrome(s);
    // Assign Flag a value of 0 or 1 depending on whether or not you find what you are looking for, in the given string
    if(flag)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}



