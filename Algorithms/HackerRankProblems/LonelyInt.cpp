/*
 * LonelyInt.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: rmhyman
 */
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
int lonelyinteger(const vector < int >& a) {
    vector<int> tmp(a);
    std::sort(tmp.begin(),tmp.end());
    auto pos = tmp.begin();
    int count = 0;
    while (pos != tmp.end()){
       count = std::count(pos,tmp.end(),*pos);
        if(count == 1){
            return *pos;
        }
        else{
            pos += count;
        }
    }

return 0;

}
int main() {
    int res;

    int _a_size;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }

    res = lonelyinteger(_a);
    cout << res;

    return 0;
}




