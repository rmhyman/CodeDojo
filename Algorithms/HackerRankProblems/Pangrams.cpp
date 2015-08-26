/*
 * Pangrams.cpp
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

bool IsPangram(const string& s){
    vector<int> letters(26,0);
    int x = 0;
    for(auto & c : s){
        x = std::tolower(c);
        if(c != ' '){
            ++letters[x%26];
        }
    }
    auto count = count_if(letters.begin(),letters.end(),[](const int num){return num > 0;});
    if(count == 26){
        return true;
    }

    return false;
}

int main() {
    string s;
    std::getline(std::cin,s);
    if(IsPangram(s)){
        cout << "pangram" << endl;
    }
    else{
        cout << "not pangram" << endl;
    }
    return 0;
}




