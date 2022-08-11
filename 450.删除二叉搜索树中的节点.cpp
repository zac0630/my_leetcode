/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    //先遍历寻找，再修改接收。框架先写出来
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return NULL;
        if(root->val == key){
            //找到了 需要删除
            if(root->left == NULL)  return root->right;
            if(root->right == NULL) return root->left;
            //找到右子树的最小节点
            TreeNode* minNode = getMin(root->right);
            //删除右子树中的这个节点
            root->right = deleteNode(root->right, minNode->val);
            //右子树的最小节点与root交换
            minNode->left = root->left;
            minNode->right = root->right;
            root = minNode;
        }else if(root->val > key){
            root->left = deleteNode(root->left, key);
        }else if(root->val < key){
            root->right = deleteNode(root->right, key);
        }
        return root;
    }

    TreeNode* getMin(TreeNode* node){
        //左小右大，找最小节点
        //等价于找最左的节点
        while (node->left != NULL)  node = node->left;
        return node;
        
    }
};
// @lc code=end

