/*
 * MaximizingXor.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: rmhyman
 */
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/*
 * Complete the function below.
 */
int maxXor(int l, int r) {
    int max_xor = 0;
    for(auto i = l; i <= r; ++i){
        for(auto j = l; j <= r; ++j){
            int result = i ^ j;
            if(result > max_xor){
                max_xor = result;
            }
        }
    }
    return max_xor;


}

int main() {
    int res;
    int _l;
    cin >> _l;

    int _r;
    cin >> _r;

    res = maxXor(_l, _r);
    cout << res;

    return 0;
}




