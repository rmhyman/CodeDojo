/*
 * GridSearch.cpp
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

bool PatternFound(const std::vector<string>& g, const std::vector<string>& p, int row,unsigned start_index ){
        //cout << "made it" << endl;
    int num_rows_p = p.size();
    int p_row = 1;
    int max = row + num_rows_p;
   // cout << "max is " << max << endl;
    //cout << "row is " << row << endl;
    //return false;
    for(int i = row + 1; i < max; ++i){
     //   cout << "string in g " << g[i] << endl;
      //  cout << "string in p " << p[p_row] << endl;
        size_t pos = g[i].find(p[p_row],start_index);
        if( pos == string::npos || pos != start_index){
            return false;
        }
        ++p_row;
    }
    return true;

}

string IsPatternInGrid(const std::vector<string>& g, const std::vector<string>& p){

    int num_rows_g = g.size();
    int num_rows_p = p.size();
    int col_width_p = p[0].size();
    int col_width_g = g[0].size();
    if(num_rows_g == 1){
        if(g[0].find(p[0]) != string::npos)
            return "YES";
    }
    for(int i = 0; i < num_rows_g; ++i){
        if(num_rows_g - i + 1 < num_rows_p){
            return "NO";
        }
        size_t start_index = g[i].find(p[0]);
       // cout << start_index << endl;
        //cout << string::npos << endl;
        while(start_index != string::npos){
            if(PatternFound(g,p,i,start_index)){
        //cout << "i is " << i << endl;
                return "YES";
            }
            start_index = g[i].find(p[0],start_index+1);
        }
    }
    return "NO";
}
int main() {
    int t;
    int R,C;
    int r,c;
    cin >> t;
    while(t--){
        cin >> R >> C;
        std::vector<string> grid;
        grid.reserve(C);
        string s;
        while(R--){
            cin >> s;
            grid.push_back(s);
        }
        cin >> r >> c;
        std::vector<string> pattern;
        pattern.reserve(c);
        while(r--){
            cin >> s;
            pattern.push_back(s);
        }
        cout << IsPatternInGrid(grid,pattern) << endl;
    }
    return 0;
}




