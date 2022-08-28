/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
// #include "common.h"
//如何判断是左叶子（叶子节点是可以判断的）
class Solution {
int sum = 0;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        traverse(root);
        return sum;
    }
    void traverse(TreeNode* root){
        if(root == NULL)
            return;
        if(root->left != NULL && root->left->left == root->left->right){
            sum += root->left->val;
        }
        traverse(root->left);
        traverse(root->right);
    }
};
// @lc code=end

