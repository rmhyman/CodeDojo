/*
 * SherlockGcd.cpp
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
vector<int> ComputePrimes(const int max){

    vector<int> primes(max);
    primes.reserve(max);
    std::iota(primes.begin(),primes.end(),1);
    double upper_bound = std::sqrt(static_cast<double>(max));
    upper_bound = std::floor(upper_bound);
    //cout << "upper bound " << upper_bound << endl;
    for(int i = 2; i <= static_cast<int>(upper_bound); ++i){
        for(int j = i * i; j <= max; j+=i){
           primes[j-1] = -1;
        }
    }

  //  vector<int> primes(potential_primes);
    //for(auto num : potential_primes){
       primes.erase(std::remove_if(primes.begin(),primes.end(),[](const int val){return (val == -1 || val == 0);}),primes.end());
    //}
    return primes;
}
int ComputeGcd(const int a, const int b){
    int in1 = a;
    int in2 = b;
    int intermediate = 0;
    while(in2 != 0){
        intermediate = in2;
        in2 = in1 % in2;
        in1 = intermediate;
    }
    return in1;
}
string DoesGcdSetExist(const vector<int>& set_){
    int size = set_.size();
    vector<int>set(size);
    std::unique_copy(set_.begin(),set_.end(),set.begin());
    std::sort(set.begin(),set.end());
    auto min = set[0];
    int result = 0;
    if(min == 1){
        return "YES";
    }
    if(set.size() == 1){
        return "NO";
    }
    else{

           result = ComputeGcd(set[0],set[1]);
        if(result == 1){
                            return "YES";
                        }
            for(int i = 2; i < size; ++i){
                result = ComputeGcd(set[i],result);
                        if(result == 1){
                            return "YES";
                        }

                    }
                }



    return "NO";
}
vector<int> ConstructSet(const int num_vals){
        vector<int> set;
        set.reserve(num_vals);
        int val =0;
        for(int i = 0; i < num_vals; ++i){
            cin >> val;
            set.push_back(val);
        }
    return set;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int t;
    cin >> t;
    int n;
    while(t--){
        cin >>n;
    vector<int> set = ConstructSet(n);
        cout << DoesGcdSetExist(set) << endl;
    }
    return 0;
}




