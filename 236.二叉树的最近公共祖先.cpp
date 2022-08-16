/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// #include "common.h"
class Solution {
public: 
    //寻找与p、q节点有交叉的最浅节点（分类讨论，p和q共两种情况）
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return find(root, p, q);
    }
    TreeNode* find(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL)    return NULL;

        //case1 p或者q在一条连线上
        if(root->val == p->val || root->val == q->val)
            return root;

        TreeNode* left = find(root->left, p, q);
        TreeNode* right = find(root->right, p ,q);
        //case2 在root的左子树和右子树分别找到了p和q
        //root是公共祖先
        if(left != NULL && right != NULL)
            return root;
        
        return left != NULL ? left : right;
    }
};
// @lc code=end

