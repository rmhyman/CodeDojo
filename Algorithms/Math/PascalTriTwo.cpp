/*
 * PascalTriTwo.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: rmhyman
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        std::vector<int> row(rowIndex+1, 0);
        for(int i = 0; i < rowIndex + 1; ++i){
	             if(i == 0){
	                 row[i] = 1;
	             }
	             else{
                    double tmp(static_cast<double>(row[i-1]) * static_cast<double>(rowIndex +1 - i));
                    double result(tmp/i);
	                 row[i] = static_cast<int>(result);
	             }

	         }

    return row;
    }
};



