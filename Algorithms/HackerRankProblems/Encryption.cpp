/*
 * Encryption.cpp
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

std::pair<int,int> CalcRowColumn(const int length){
    double root = std::sqrt(length);
    double Froot = std::floor(root);
    double Croot = std::ceil(root);
    int row = static_cast<int>(Froot);
    int column = row;
    if(row * column < length){
        column = Croot;
    }
    if(row * column < length){
        row = column;
    }
    return make_pair(row,column);
}

vector<string> EncryptMessage(const string & str, const int row, const int col){
    vector<string> tmp;
    tmp.reserve(row);
    string tmp_str(' ',row);
    int count = 0;
    for(auto ch : str){
        if(count == col){
            tmp.push_back(tmp_str);
            tmp_str.clear();
            tmp_str.insert(0, col, ' ');
            count = 0;
            tmp_str[count++] = ch;

        }
        else{
           tmp_str[count++] = ch;
        }
    }
    tmp.push_back(tmp_str);
    //for(auto s : tmp){
     //   cout << s << endl;
    //}
    return tmp;
}
void PrintEncodedMessage(const vector<string> & tmp, const int row, const int col){
    string tmp_str;
    tmp_str.reserve(col);
    for(auto  j = 0; j < col; ++j){
        for(auto i = 0; i < row; ++i ){
        //cout << "ch: " << tmp[i][j] << endl;
            if(!std::isspace(tmp[i][j])){
                tmp_str.push_back(tmp[i][j]);
            }
            else{
                //cout << "Made it here" << endl;
         //       cout << tmp_str << " ";
          //      tmp_str.clear();
                break;
            }
        }
                cout << tmp_str << " ";
                tmp_str.clear();
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string line;
    cin >> line;
std::pair<int,int> dims =  CalcRowColumn(line.size());
    //cout << "Made it here" << endl;
vector<string> message =  EncryptMessage(line, dims.first, dims.second);
    //cout << "Made it here" << endl;
     PrintEncodedMessage(message,dims.first,dims.second);
    return 0;
}



