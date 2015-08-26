/*
 * ManasaStones.cpp
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
vector<int> CalculateGuesses(const int n, const int a, const int b){

    vector<int>guesses;
    guesses.reserve(2*n);
    guesses.push_back((n-1) *a);
    guesses.push_back((n-1) * b);
    int start = 1;
    int end = n - 2;
    while(start <= end){
    guesses.push_back((start * a) + (end * b));
    guesses.push_back((start * b) + (end * a));
        ++start;
        --end;

    }


    //vector<int>unique;

    //std::unique_copy(guesses.begin(), guesses.end(), unique.begin());
    auto last = std::unique(guesses.begin(), guesses.end());
    guesses.erase(last,guesses.end());
    std::sort(guesses.begin(),guesses.end());
    return guesses;

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,n,a,b;
    cin >> t;
    vector<int> guesses;
    while(t--){
        cin>>n>>a>>b;
        guesses = CalculateGuesses(n,a,b);
        std::for_each(guesses.begin(),guesses.end(),[](const int val){cout << val << " ";});
        cout << endl;
    }
    return 0;
}




