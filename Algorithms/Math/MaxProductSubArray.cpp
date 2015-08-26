/*
 * MaxProductSubArray.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: rmhyman
 */
class Solution {
public:
    int maxProduct(int A[], int n) {
			std::vector<int> max_product(n, 0);
			std::vector<int> min_product(n,0);

			for(auto i = 0; i < n; ++i){
			    if(i == 0){
			        max_product[i] = A[i];
			        min_product[i] = A[i];
			    }
				else if(A[i] > 0){
				    max_product[i] = std::max((max_product[i-1] * A[i]), A[i]);
				    min_product[i] = std::min(min_product[i-1] * A[i], A[i]);
				}
				else if (A[i] < 0){
		    	    max_product[i] = std::max((min_product[i-1] * A[i]), A[i]);
		    	    min_product[i] = std::min((max_product[i-1] * A[i]), A[i]);
	 			}

			}
			return *std::max_element(max_product.begin(),max_product.end());
    }
};



