/*
 * ZigZag.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: rmhyman
 */
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> ret(numRows, "");
        bool reverse_order = false;
        const int size = s.size();
        int pos =0;
        int sLoc = 0;

        if(size <= numRows || numRows == 1){
            return s;
        }
        else {
            while(pos < size){
                if(sLoc == numRows - 1){
                    reverse_order = true;
                }
                else if(sLoc == 0){
                    reverse_order = false;
                }

                if(!reverse_order){
                    ret[sLoc++].push_back(s[pos++]);
                }
                else{
                    ret[sLoc--].push_back(s[pos++]);
                }
            }
        }
        string val("");
        for(auto & t : ret){
            val += t;
        }

        return val;
    }
};
