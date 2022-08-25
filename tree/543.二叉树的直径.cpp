/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
//二叉树的直径等于左子树+右子树的深度
// #include "common.h"
class Solution {
public:
    int maxDiameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return maxDiameter;        
    }

    int maxDepth(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftDiameter = maxDepth(root->left);
        int rightDiameter = maxDepth(root->right);
        maxDiameter = max(maxDiameter, leftDiameter+rightDiameter);

        return 1 + max(leftDiameter, rightDiameter);
    }

};
// @lc code=end

