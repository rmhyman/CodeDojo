/*
 * PascalTri.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: rmhyman
 */
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> pascal_tri(numRows,vector<int>(numRows));
	       int row_number = 0;
	       auto calculate_row = [&] (std::vector<int>& row) -> void {
	         for(int i = 0; i < row_number + 1; ++i){
	             if(i == 0){
	                 row[i] = 1;
	             }
	             else{

	                 row[i] = ((row[i-1] * (row_number +1 - i))/i);
	             }

	         }

	       };


	       for(row_number = 0; row_number < numRows; ++row_number){
	           vector<int> tmp(row_number + 1, 0);

	           calculate_row(tmp);
	           pascal_tri[row_number] = tmp;
	       }

	       return pascal_tri;
    }
};



