/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0){
            vector<TreeNode*> res;
            return res;
        }
        return build(1, n);
    }
    vector<TreeNode*> build(int lo, int hi){
        vector<TreeNode*> res;
        if(lo > hi){
            //构造空节点
            TreeNode* node = new TreeNode;
            node = NULL;
            res.push_back(node);
        }
        for(int i = lo; i <= hi; i++){
            vector<TreeNode*> leftTree = build(lo, i-1);
            vector<TreeNode*> rightTree = build(i+1, hi);
            //构造根节点，将根节点与左右子树合并
            for(TreeNode* left : leftTree){
                for(TreeNode* right : rightTree){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }

        }
        return res;
    }
};
// @lc code=end

