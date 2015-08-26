/*
 * MaxMin.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: rmhyman
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int ComputeMinUnfairness(const vector<int> & list , const int k){
    int min = 0;
    auto ptr1 = list.begin();
    auto ptr2 = list.begin() + (k-1);
    min = *ptr2 - *ptr1;
    ++ptr1;
    ++ptr2;
    int tmp = 0;
    while(ptr2 != list.end()){
        //cout << "Min is " << min << endl;
       tmp = *ptr2 - *ptr1;
        if(tmp < min){
            min = tmp;
        }
    ++ptr1;
    ++ptr2;
    }

    return min;

}
int main() {
    int N, K, unfairness = INT_MAX;
    cin >> N >> K;
    vector<int> list(N,0);
    for (int i=0; i<N; i++)
        cin >> list[i];
   sort(list.begin(), list.end());
    unfairness = ComputeMinUnfairness(list,K);
    /** Write the solution code here. Compute the result, store in  the variable unfairness --
    and output it**/
    cout << unfairness << "\n";
    return 0;
}




