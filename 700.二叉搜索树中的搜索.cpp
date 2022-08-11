/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL)
            return NULL;
        //左子树搜索
        if(root->val > val)
            return searchBST(root->left, val);
        //右子树
        if(root->val < val)
            return searchBST(root->right, val);
        
        return root;
    }
};
// @lc code=end

