/*
 * CavityMap.cpp
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
vector<string> ConstructMap(const int num) {
    vector<string> map;
    map.reserve(num);
    string tmp;
    for(int i = 0; i < num; ++i){
       cin >> tmp;
       map.push_back(tmp);
    }
    return map;
}
bool IsNeighborLower(const char cell, const char neighbor){
    string c(1,cell);
    string n(1,neighbor);
    int num1 = std::stoi(c);
    int num2 = std::stoi(n);
    return (num2 < num1);
}
vector<string> GenCavityMap(const vector<string>& map, const int width){
    vector<string> cav_map(map);
    bool top_is_less, bottom_is_less, right_is_less, left_is_less;
    for(int i = 1; i < width -1; ++i){
        for(int j = 1; j < width -1; ++j){
            top_is_less =  IsNeighborLower(map[i][j], map[i-1][j]);
            bottom_is_less =IsNeighborLower(map[i][j], map[i+1][j]);
            right_is_less =IsNeighborLower(map[i][j], map[i][j + 1]);
            left_is_less =IsNeighborLower(map[i][j], map[i][j - 1]);

            if(top_is_less && bottom_is_less  &&  right_is_less && left_is_less){
                cav_map[i][j] = 'X';
            }
        }

    }
    return cav_map;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int dimensions = 0;
    cin >> dimensions;
    vector<string> cav_map =ConstructMap(dimensions);
    cav_map = GenCavityMap(cav_map,dimensions);
    std:for_each(cav_map.begin(),cav_map.end(),[](const string & s){ cout << s << endl;});
    return 0;
}




