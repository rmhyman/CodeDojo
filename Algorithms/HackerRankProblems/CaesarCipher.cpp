/*
 * CaesarCipher.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: rmhyman
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

char EncryptChar(const char c, const int k){
    int inc = k %26;
    char ret;
    if(!isalpha(c)){
        return c;
    }
    else if(islower(c)){
            int diff_to_end = 'z' - c;
            if(c + inc > 'z'){
                int remain = (c+inc) - 'z' ;
                ret = 'a' + static_cast<char>(remain-1);
                //cout << "inc is " << inc << endl;
                //cout << "ret is " << ret << endl;
            }
            else{
                ret = c + inc;
            }
        }
    else if(isupper(c)){
            //cout << "inc is " << inc << endl;
            int diff_to_end = 'Z' - c;
            if(c + inc > 'Z'){
                int remain = (c+inc) - 'Z';
                ret = 'A' + static_cast<char>(remain-1);
                //cout << "remain is " << remain << endl;
                //cout << "ret is " << ret << endl;
            }
            else{
                ret = c + inc;
            }
        }
    else{
        assert("Did not register as lower case char" == 0);
    }

    return ret;
}

string EncryptString(const string& s_,const int k){
    string s;
    s.reserve(s_.size());
    char c;
    for(auto & c_ : s_){
        c = EncryptChar(c_,k);
        s.push_back(c);
    }
    return s;

}
int main() {
    int n,k;
    cin >> n;
    string s;
    s.reserve(n);
    cin  >> s;
    cin >> k;
    cout << EncryptString(s,k) << endl;
    return 0;
}



