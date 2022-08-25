/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    TreeNode* invertTree(TreeNode* root) {
        traverse(root);
        return root;
    }
    TreeNode* temp = NULL;
    void traverse(TreeNode* root){
        if(root == NULL)
            return;
        //前序位置和后序位置交换左右节点都可以
        temp = root->left;
        root->left = root->right;
        root->right = temp;

        traverse(root->left);
        //中序位置不可以，因为会把已经交换好的左子树换到右边
        //未交换的右子树换到左边，
        //所以还需要继续对左子树进行交换traverse(root->left);
        traverse(root->right);
    }
};
// @lc code=end


//递归
//定义：将以root为根的这棵二叉树反转，返回二叉树的根节点
TreeNode* inverTree(TreeNode* root){
    if(root == NULL)
        return NULL;
    //先反转左子树，再反转右子树
    inverTree(root->left);
    inverTree(root->right);
    //最后反转左右节点
    TreeNode* temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;
}
