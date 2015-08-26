/*
 * NumOfOnes.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: rmhyman
 */
class Solution {
public:
    int hammingWeight(uint32_t n) {

        unsigned ham_weight = 0;
        if(n == 1){
            return 1;
        }
        if(n & 0x1){
            ++ham_weight;
        }
        while(n != 0){
            if((n >> 1) & 0x1){
                ++ham_weight;
            }
            n>>=1;
        }
        return ham_weight;
    }
};



