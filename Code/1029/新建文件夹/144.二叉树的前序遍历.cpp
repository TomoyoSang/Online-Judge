/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
#include <stack>
using namespace std;


class Solution {
public:

    vector<int> preorderTraversal(TreeNode* root) 
    {
        TreeNode* p;
        vector<int> pre_ans;
        stack<TreeNode> my_stack;
        my_stack.push(root);
        while(!my_stack.empty())
        {
            p=my_stack.pop();
            pre_ans.insert(pre_ans.end(),p->val);
            if(p->left!=NULL)my_stack.push(p->left);
            if(p->right!=NULL)my_stack.push(p->right);
        }
        return pre_ans;
    }
};

