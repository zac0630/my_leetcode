/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
private:
    int num;
public:
    TreeNode* convertBST(TreeNode* root) {
        num = 0;
        traverse(root);
        return root;
    }
    void traverse(TreeNode* root){
        if(root == NULL)
            return;
        traverse(root->right);
        //维护累加和
        num += root->val;
        //将BST转化成累加树
        root->val = num;
        traverse(root->left);
    }
};
// @lc code=end

