/*
 * lastWordLength.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: rmhyman
 */
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()){
            return 0;
        }
        else{
            auto pos = s.find_first_not_of(' ');
            if(pos == std::string::npos){
                return 0;
            }
            pos = s.find_last_of(' ');
            if(pos != std::string::npos){
                return s.size() - pos - 1;
            }
            else{
                return s.size();
            }
        }

    }
};


