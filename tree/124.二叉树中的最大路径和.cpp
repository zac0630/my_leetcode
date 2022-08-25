/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
int res = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        oneSideMax(root);
        return res;
    }
    //定义：记录从根节点到叶子节点的单边最大路径
    int oneSideMax(TreeNode* root){
        if(root == NULL)
            return 0;
        int left = max(0, oneSideMax(root->left));
        int right = max(0, oneSideMax(root->right));

        int pathMaxSum = root->val + left + right;
        res = max(res, pathMaxSum);

        return root->val + max(left , right);
    }
};
// @lc code=end

