/*
 * SearchInsertPos.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: rmhyman
 */
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        std::vector<int> array(n, 0);

        for(auto i = 0; i < n; ++i){
            array[i] = A[i];
        }
        auto found = std::find(array.begin(), array.end(),target);
        if(found not_eq array.end()){
            if (std::distance(array.begin(), found) == 0){
                return 0;
            }
            else{
                return std::distance(array.begin(), found);
            }
        }
        else{
            array.push_back(target);
            std::sort(array.begin(), array.end());
            found = std::find(array.begin(), array.end(),target);
            if (std::distance(array.begin(), found) == 0){
                return 0;
            }
            else{
                return std::distance(array.begin(), found);
            }
        }
    }
};



