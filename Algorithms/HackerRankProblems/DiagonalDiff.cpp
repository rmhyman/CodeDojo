/*
 * DiagonalDiff.cpp
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

int ComputeLeftDiag(const vector<vector<int>>& m){
    int size = m.size();
    int sum = 0;
    for(int i = 0; i < size; ++i){
        sum += m[i][i];
    }
    return sum;
}
int ComputeRightDiag(const vector<vector<int>>& m){
    int size = m.size();
    int sum = 0;
    int row = 0;
    for(int i = size - 1; i >= 0; --i){
        sum += m[row][i];
        ++row;
    }
    return sum;
}
int main() {
    int n;
    cin >> n;
    int input;
    vector<vector<int>> m(n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> input;
            m[i].push_back(input);
        }
    }
    int left = ComputeLeftDiag(m);
    int right = ComputeRightDiag(m);
    cout << std::abs(left-right) << endl;
    return 0;
}




