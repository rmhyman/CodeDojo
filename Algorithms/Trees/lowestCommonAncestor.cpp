/*
 * lowestCommonAncestor.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: rmhyman
 */
#include<tuple>
#include<stack>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 void ReduceStackSize(stack<TreeNode*>& s, int limit){
     while(s.size() != limit){
         s.pop();
     }
 }
 std::tuple<stack<TreeNode*>,bool> ComputeLcaPath(TreeNode* root, TreeNode* node, TreeNode* other){
     stack<TreeNode*> path;
     bool found_other = false;
     if(root == node){
         path.push(root);
         return make_tuple(path,false);
     }
     else{
         TreeNode* tmp = root;
         while(tmp != node){
             if(tmp == other){
                 found_other = true;
                 return make_tuple(path,found_other);
             }
             path.push(tmp);
             if(node->val > tmp->val){
                 tmp = tmp->right;
             }
             else{
                 tmp = tmp->left;
             }
         }
     }
     return make_tuple(path,found_other);
 }
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root == p || root == q){
           return root;
       }
       else{
           bool found_q = false;
           bool found_p = false;
           stack<TreeNode*> lca_A;
           stack<TreeNode*> lca_B;
           std::tie(lca_A,found_q) = ComputeLcaPath(root,p,q);
           std::tie(lca_B,found_p) = ComputeLcaPath(root,q,p);

           if(found_q){
               return q;
           }
           if(found_p){
               return p;
           }
           if(lca_A.size() > lca_B.size()){
               ReduceStackSize(lca_A,lca_B.size());
           }
           else{
               ReduceStackSize(lca_B,lca_A.size());
           }
           while(!lca_A.empty()){
               TreeNode* a = lca_A.top();
               TreeNode* b = lca_B.top();
               lca_A.pop();
               lca_B.pop();
               if(a == b){
                   return a;
               }
           }
       }
       return root;
    }
};



