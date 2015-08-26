/*
 * PalindromeIndex.cpp
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

int PalindromeIndex(const string & s,bool is_second_time){
    auto p1 = s.begin();
    auto p2 = s.end() - 1;
    if(s.size() == 1){
        return -1;
    }

    //auto tmp1 = s.begin() + 4274;
    //auto tmp2 = s.end() - 4275;
    for(; std::distance(p1,p2) >= 0; ++p1,--p2){

        if(!is_second_time && (*p1 != *p2)){
            string tmp(s);
            int pos = std::abs(p1 - s.begin());
            auto p3 = tmp.begin() + pos;
            tmp.erase(p3);
            if(PalindromeIndex(tmp,true) == -1){
                return pos;
            }
            else{
            pos = std::abs(p2 - s.begin());
                return pos;
            }
        }
        else if(is_second_time && (*p1 != *p2)){
            return -2;
        }
        if((std::distance(p1,p2) == 0) && (s.size() % 2 == 1)){
        int midpoint = s.size()/2;
            string tmp(s);
            auto p3 = tmp.begin() + midpoint;
           int pos = std::abs(p3 - tmp.begin());
            tmp.erase(p3);
            if(!is_second_time && PalindromeIndex(tmp,true) == -1){
                return pos;
            }
        }
    }

    return -1;
}
int main() {

    int t;
    string s;
    s.reserve(100005);
    cin >> t;
    while(t--){
        cin >> s;
        cout << PalindromeIndex(s,false) << endl;
    }

    return 0;
}




