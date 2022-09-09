/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
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
//思路：举反例，第二小的值会出现在哪里
//情况一：[2, 2, 99, 2, 3]，第二小值在左子树中。
//情况二：[2, 2, 2, 2, 3, 2, 4]，第二小的值需要将左右子树的第二小的值都计算出来，比较其中较小的元素，作为整棵树的第二小元素
class Solution {
public:
    //返回以root为根的第二小的值，如果不存在，则返回-1
    int findSecondMinimumValue(TreeNode* root) {
        if(root->left == root->right)
            return -1;
        //记录左右节点的值
        int left = root->left->val;
        int right = root->right->val;

        //如果左节点的值和root值相同，递归进左子树，找第二小的值
        if(left == root->val)
            left = findSecondMinimumValue(root->left);
        if(right == root->val)
            right = findSecondMinimumValue(root->right);

        //当左子树全为root的值，即左子树没有第二小的值
        if(left == -1)  return right;
        if(right == -1) return left;
        
        return min(left, right);
    }
};
// @lc code=end

