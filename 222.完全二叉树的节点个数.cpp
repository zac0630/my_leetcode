/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        TreeNode* l = root;
        TreeNode* r = root;
        int lh = 0; int rh = 0;
        //计算左右子树的高度
        while(l != NULL){
            l = l->left;
            lh++;
        }
        while(r != NULL){
            r = r->right;
            rh++;
        }
        // 如果左右侧计算的高度相同，则是一棵满二叉树
        if(lh == rh){
            return countPerfectTreeNodes(root);
        }
        // 如果左右侧的高度不同，则按照普通二叉树的逻辑计算
        return 1 + countTreeNodes(root->left) + countTreeNodes(root->right);
    }
    int countTreeNodes(TreeNode* root){
        if(root == NULL)
            return 0;
        return 1 + countTreeNodes(root->left) + countTreeNodes(root->right);
    }
    int countPerfectTreeNodes(TreeNode* root){
        int h = 0;
        //计算树的高度
        while(root != NULL){
            root = root->left;
            h++;
        }
        //节点总数是2^h - 1
        return (int)pow(2, h) - 1;
    }
};
// @lc code=end

