/*
 * AlternatingChars.cpp
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

unsigned int NumDeletions(const string & s){
    unsigned pos = 0;
    unsigned num_deletes = 0;
    //cout << "size of s equals " << s.size() << endl;
    while(pos < s.size()){
        if(s[pos] == 'A'){
            ++pos;
            while(pos < s.size() &&  s[pos] != 'B'){
               // cout << "not a B" << endl;
                ++num_deletes;
                ++pos;
                //cout << "pos equals " << pos << endl;
            }
        }
        else if(s[pos] == 'B'){
            ++pos;
            while(pos < s.size() &&  s[pos] != 'A'){
               // cout << "pos equals " << pos << endl;
                //cout << "not a A" << endl;
                ++num_deletes;
                ++pos;
            }
        }


    }
    return num_deletes;
}
int main() {
    int t;
    cin >> t;
    string s;
    s.reserve(10000);
    while(t--){
    cin >> s;
     cout << NumDeletions(s) << endl;
    }
    return 0;
}




