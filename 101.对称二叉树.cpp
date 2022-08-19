/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
//轴对称
//两颗左右子树的根节点的值要相同，再去判断各自的子树，共四条
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return check(root->left, root->right);
    }
    bool check(TreeNode* left, TreeNode* right){
        if(left == NULL || right == NULL)
            return left == right;
        //下面是left和right都不为空的情况
        //两颗左右子树的根节点的值需要相同
        if(left->val != right->val)
            return false;
        return check(left->left, right->right) && check(left->right, right->left);
    }
};
// @lc code=end

