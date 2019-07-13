/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
using namespace std;


int ifront=0;
vector<int> ans;
class Solution {
public:
    void midorder(TreeNode* root)
    {
        if(root==nullptr)return;
        if(root->left!=NULL)midorder(root->left);
        ans.insert(ans.end(),root->val);
        if(root->right==NULL)midorder(root->right);
        return ;
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        midorder(root);
        return ans;
    }
   
};

