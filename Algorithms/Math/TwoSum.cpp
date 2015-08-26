/*
 * TwoSum.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: rmhyman
 */


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_multimap<int,int> table;
        int index = 0;
        for(auto & num : nums){
            table.insert({num,index});
            ++index;
        }
        index = 0;
        int index2 = 0;
        for(auto & num : nums){
            int remainder = target - num;
            if(remainder == num){
                auto pos = table.find(remainder);
                if(pos != table.end() && pos->second == index){
                    table.erase(pos);
                    pos = table.find(remainder);
                    if(pos != table.end()){
                        index2 = pos->second;
                        break;
                    }
                }
                else{
                    index2 = pos->second;
                    break;
                }
            }
            else{
                auto pos = table.find(remainder);
                if(pos != table.end()){
                    index2 = pos->second;
                    break;
                }
            }
            ++index;
        }

        ++index;
        ++index2;
        vector<int> solution;
        if(index < index2){
            solution.push_back(index);
            solution.push_back(index2);
        }
        else{
            solution.push_back(index2);
            solution.push_back(index);
        }
        return solution;
    }
};
