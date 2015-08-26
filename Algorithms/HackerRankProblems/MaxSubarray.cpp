/*
 * MaxSubarray.cpp
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
void PrintArray(const vector<int> & v){
    for(auto& num : v){
        cout << num << " ";
    }
    cout << endl;
}
int MaxSum(const vector<int> & ar){
    vector<int> sums(ar.size(),0);
    sums[0] = ar[0];
    int tmp = 0;
    for(int i = 1; i < sums.size(); ++i){

        tmp = sums[i-1] + ar[i];
        if(tmp > ar[i]){
            sums[i] = tmp;
        }
        else{
            sums[i] = ar[i];
        }
    }
    //PrintArray(sums);
   auto max = max_element(sums.begin(),sums.end());
   return *max;
}
int MaxSumNonContigous(const vector<int>& ar_){

    vector<int> ar(ar_);
   std::sort(ar.begin(),ar.end());
    auto pos = std::find_if(ar.begin(),ar.end(),[](const int i){return i > 0;});
    if(pos == ar.end()){
        return ar.back();
    }
    else{
        int sum = 0;
        for(;pos != ar.end(); ++pos){
            sum += *pos;
        }
        return sum;
    }
    return -1;
}

int main() {
    int t;
    int n;
    vector<int> ar;
    cin >> t;
    while(t--){
       cin >> n;
        int tmp;
       ar.reserve(n);
       for(int i = 0; i < n; ++i){
          cin >> tmp;
           ar.push_back(tmp);
       }
        cout << MaxSum(ar) << " " << MaxSumNonContigous(ar) << endl;
        ar.clear();
      }
    return 0;
}




