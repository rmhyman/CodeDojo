/*
 * UtopianTree.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: rmhyman
 */
#include <iostream>
using namespace std;

int height(int n) {
    int height = 1;
    if (n == 0){
        return height;
    }
    else {
       for(auto i = 1; i <= n; ++i){
            if(i % 2 == 1){
                height *= 2;
            }
            else{
                height += 1;
            }
        }
    }
    return height;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << height(n) << endl;
    }
}




