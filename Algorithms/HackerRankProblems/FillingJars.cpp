/*
 * FillingJars.cpp
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
class Dictionary{
    public:
    Dictionary(long long unsigned int n)
        : num_jars(n)
    {
    }
    ~Dictionary() {};
    void Insert(long long unsigned int start, long long unsigned int end, double amount){
        double diff = end - start + 1;
        total_ += (diff * amount);

    }
    long long int GetAverage(){
        return static_cast<long long unsigned int>(floor(total_ / num_jars));
    }

    private:
    long double total_ = 0;
    long double num_jars = 0;
};

int main() {
    long long unsigned int n, m;
    long long unsigned int a,b,k;
    cin >> n >> m;
    Dictionary dict(n);
    while (m--){
        cin >> a >> b >> k;
        dict.Insert(a,b,k);
    }

    cout << dict.GetAverage() << endl;

    return 0;
}




