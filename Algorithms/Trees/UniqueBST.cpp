/*
 * UniqueBST.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: rmhyman
 */
class Solution {
public:
    int numTrees(int n) {
        std::vector<int> unique_trees_per_levl(n + 1,0);
        if(n == 1 or n == 0){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        else{

            unique_trees_per_levl[0] = 0;
            unique_trees_per_levl[1] = 0;
            unique_trees_per_levl[2] = 2;
            int sum = 0;
            for(auto i = 2; i < n; ++i){
                int subtree_height_r = i;
                int subtree_height_l = 0;
                while(subtree_height_r >= 0){
                    int sum_right =  unique_trees_per_levl[subtree_height_r--];
                    int sum_left = unique_trees_per_levl[subtree_height_l++];
                    if(sum_right + sum_left == 0){
                        sum += 1;
                    }
                    if(sum_right != 0 && sum_left != 0)
                    {
                        sum += (sum_right * sum_left);
                    }
                    else{
                      sum += (sum_right + sum_left);
                    }

                }
                unique_trees_per_levl[i+1] = sum;
                sum = 0;
            }
        }

        return unique_trees_per_levl[n];

    }
};
