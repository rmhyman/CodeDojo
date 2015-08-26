/*
 * PathSum.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: rmhyman
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(root == nullptr){
            return false;
        }
        if(root->left == nullptr and root->right == nullptr){
		return root->val == sum;
	}

	std::pair<bool,bool> results = make_pair(false,false);
	if(root->left != nullptr){
		results.first = hasPathSum(root->left, sum - root->val);
	}
	if(root->right != nullptr){
		results.second = hasPathSum(root->right, sum - root->val);
	}

	return (results.first or results.second);
    }
};



