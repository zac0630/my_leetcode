/*
 * @lc app=leetcode.cn id=998 lang=cpp
 *
 * [998] 最大二叉树 II
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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(root == NULL)
            return new TreeNode(val);
        if(root->val < val){
            //root的值是最大的，如果新加入的val值比root大，说明root应该是val节点的左子树
            TreeNode* temp = root;
            root = new TreeNode(val);
            root->left = temp;
        }
        else{
            //如果val不是最大的，那么应该在root的右子树中的某个位置上
            root->right = insertIntoMaxTree(root->right, val);
        }
        return root;
    }
};
// @lc code=end

