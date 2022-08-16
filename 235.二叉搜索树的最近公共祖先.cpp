/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int val1 = min(p->val, q->val);
        int val2 = max(p->val, q->val);
        return find(root,val1, val2);
    }
    TreeNode* find(TreeNode* root, int val1, int val2){
        if(root == NULL)
            return NULL;
        //root满足val1<=root<=val2 即找到公共祖先
        if(root->val >= val1 && root->val <= val2){
            return root;
        }
        if(root->val > val2){
            return find(root->left, val1, val2);
        }else{
            return find(root->right, val1, val2);
        }
    }
};
// @lc code=end

