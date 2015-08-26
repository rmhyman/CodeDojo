/*
 * TimeConversion.cpp
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

int GetHour(const string& s){
    int h = std::stoi(s.substr(0,2));
    if(s.find("AM") == std::string::npos){
        if(h != 12)
            h += 12;
    }
    else if(h == 12){
        h = 0;
    }
    return h;


}
int main() {

    string s;
    cin >> s;
    int hour = GetHour(s);

    string hr = to_string(hour);
    if(hour < 10){
        hr = '0' + hr;
    }
    s.erase(s.end() - 2,s.end());
    s.erase(s.begin(),s.begin() + 2);
    cout << hr+s << endl;

    return 0;
}




