/*
 * PlusMinus.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: rmhyman
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <tuple>
using namespace std;

tuple<double,double,double> DoCalc(const vector<int>& v){
    double pos = 0;
    double neg = 0;
    double zeros = 0;
    for_each(v.begin(),v.end(),[&](const int x){if(x > 0)++pos; if(x < 0) ++neg; if(x == 0)++zeros;});
    return make_tuple(pos,neg,zeros);
}
int main() {
    int n;
    cin >> n;
    int in;
    vector<int> v(n,0);
    double pos,neg,zeros;
    for(int i = 0; i < n; ++i){
        cin >> in;
        v[i] = in;
    }
    std::tie(pos,neg,zeros) = DoCalc(v);
    double res1 = pos/n;
    double res2 = neg/n;
    double res3 = zeros/n;
    cout << std::setprecision(4) << res1 << endl;
    cout << std::setprecision(4) << res2 << endl;
    cout << std::setprecision(4) << res3 << endl;
    return 0;
}




