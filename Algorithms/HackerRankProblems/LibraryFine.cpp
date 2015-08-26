/*
 * LibraryFine.cpp
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

struct Date{
    Date(int d, int m, int y): day(d),month(m),year(y){};
    int day = 0;
    int month = 0;
    int year = 0;
};

int CalcFine(const Date& actual, const Date& expected){
    if(actual.year > expected.year){
        return 10000;
    }
    else if((actual.year == expected.year) && (actual.month > expected.month)){
        return 500 * (actual.month - expected.month);
    }
    else if((actual.year == expected.year) && (actual.month == expected.month) &&
           (actual.day > expected.day)){
        return 15 * (actual.day - expected.day);
    }

    return 0;
}
int main() {
    int d,m,y;
    cin >> d >> m >> y;
    Date actual(d,m,y);
    cin >> d >> m >> y;
    Date expected(d,m,y);
    cout << CalcFine(actual,expected) << endl;
    return 0;
}



