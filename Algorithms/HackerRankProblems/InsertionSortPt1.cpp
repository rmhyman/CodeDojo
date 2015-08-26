/*
 * InsertionSortPt1.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: rmhyman
 */
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
void PrintArray(const vector<int>& ar){
    for(auto & num : ar){
        cout << num << " ";
    }
    cout << endl;
}
void insertionSort(vector <int>&  ar) {

    int pos = ar.size() - 1;
    int val = ar[pos];
    while(pos > 0){
        if(val < ar[pos - 1]){
            ar[pos] = ar[pos - 1];
        }
        else{
            ar[pos] = val;
            PrintArray(ar);
            return;
        }
        PrintArray(ar);
        --pos;
    }
    ar[0] = val;
    PrintArray(ar);



}

int main(void) {
   vector <int>  _ar;
   int _ar_size;
cin >> _ar_size;
for(int _ar_i=0; _ar_i<_ar_size; ++_ar_i) {
   int _ar_tmp;
   cin >> _ar_tmp;
   _ar.push_back(_ar_tmp);
}

insertionSort(_ar);

   return 0;
}




