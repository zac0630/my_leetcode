/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include "common.h"
class Solution {
public:
    vector<int> presort;
    vector<int> preorderTraversal(TreeNode* root) {
        traverse(root);
        return presort;
    }
    void traverse(TreeNode* root){
        if(root == NULL){
            return;
        }
        presort.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }
};
// @lc code=end

//迭代
//利用栈的特性
vector<int> preorderTraversal(TreeNode* root){
    vector<int> res;
    if(root == NULL){
        return res;
    }
    stack<TreeNode*> stk;
    TreeNode* node = root;
    while(!stk.empty() || node != NULL){
        while(node != NULL){
            res.emplace_back(node->val);
            stk.emplace(node);
            node = node->left;
        }
        node = stk.top();
        stk.pop();
        node = node->right;
    }
}