/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    //每个节点都要遍历
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        //递归计算左右子树的高度，另起一个函数
        //如何体现左右两个子树的高度
        int left = depth(root->left);
        int right = depth(root->right);
        //当前节点的左右子树的高度对比
        if(abs(left - right) > 1){
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
    //返回以root为根的高度
    int depth(TreeNode* root){
        if(root == NULL)
            return 1;
        return 1 + max(depth(root->left), depth(root->right));
    }
};
// @lc code=end

