/*
 * ServiceLane.cpp
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

vector<int> InitServiceLane(const int num_segments);
int LargestPossibleVehicle(const vector<int>& lane, const int start, const int end);
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int num_test_cases = 0;
    int num_width_segments = 0;
    cin >> num_width_segments;
    cin >> num_test_cases;
    vector<int> service_lane = InitServiceLane(num_width_segments);
    int input1 = 0;
    int input2 = 0;
    int result = 0;

    for(int i = 0; i < num_test_cases; ++i){
        cin >> input1;
        cin >> input2;
        result = LargestPossibleVehicle(service_lane,input1,input2);
        cout << result  << endl;
    }
    return 0;
}
vector<int> InitServiceLane(const int num_segments){
    vector<int> lane;
    lane.reserve(num_segments);
    int val = 0;
    for(int i =0; i < num_segments; ++i){
        cin >> val;
        lane.push_back(val);
    }
    return lane;
}
int LargestPossibleVehicle(const vector<int>& lane, const int start, const int end){
    auto largest_vehicle = std::min_element(lane.begin() + start, lane.begin() + end + 1);
    return *largest_vehicle;
}



