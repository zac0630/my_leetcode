/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
//二叉搜索树特性，中序遍历是有序的
//思路一：在中序位置记录差值，比较大小。与寻找二叉树中的众数类似
class Solution {
private:
    //记录最小的绝对差
    int minAbs = INT_MAX;
    //记录前一个节点
    TreeNode* prev = NULL;
public:
    int getMinimumDifference(TreeNode* root) {
        if(root == NULL)
            return minAbs;
        traverse(root);
        return minAbs;
    }
    void traverse(TreeNode* root){
        if(root == NULL)
            return;
        traverse(root->left);

        if(prev != NULL)
            minAbs = min(minAbs, (root->val - prev->val));
        // if(prev == NULL){
        //     minAbs = root->val;
        // }
        // else{
        //     minAbs = min(minAbs, (root->val - prev->val));
        // }
        prev = root;

        traverse(root->right);
    }
};
// @lc code=end

