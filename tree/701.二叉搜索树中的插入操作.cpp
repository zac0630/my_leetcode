/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    //insertIntoBST构造值为val的新节点
    //如果当前节点为空，构造新节点并返回；
    //如果val值比root小，说明val新节点属于root->left
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)
            return new TreeNode(val);
        if(root->val > val)
            root->left = insertIntoBST(root->left, val);
        if(root->val < val)
            root->right = insertIntoBST(root->right, val);
        return root;
    }
};
// @lc code=end

