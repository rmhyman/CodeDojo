/*
 * BalancedBinTree.cpp
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
    bool isBalanced(TreeNode *root) {
        function<int (TreeNode*)> getheight = [&getheight] (TreeNode* node) -> int {
		if(node == nullptr){
			return 0;
		}
		if(node->left == nullptr and node->right == nullptr){
			return 1;
		}
		unsigned left_height = 0;
		unsigned right_height = 0;
		if(node->left != nullptr){
			left_height = 1 + getheight(node->left);
		}
		if(node->right != nullptr){
			right_height = 1 + getheight(node->right);
		}
		return std::max(left_height,right_height);
	};
	int lhs,rhs;
	if(root == nullptr){
		return true;
	}
	else if(root->left == nullptr and root->right == nullptr){
		return true;
	}
	else{
		lhs = getheight(root->left);
		rhs = getheight(root->right);
	}

	return ((std::abs(lhs - rhs) <= 1) and isBalanced(root->left) and isBalanced(root->right));
    }
};



