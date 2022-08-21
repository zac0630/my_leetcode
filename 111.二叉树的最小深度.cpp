/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        if(root == NULL)    return 0;
        int depth = 1;
        //基于二叉树层序遍历
        queue<TreeNode*> q;
        q.push(root);
        int len = 0;
        while(!q.empty()){
            len = q.size();
            for(int i = 0; i < len; i++){
                TreeNode* cur = q.front();
                if(cur->left == NULL && cur->right == NULL){
                    return depth;
                }
                if(cur->left != NULL){
                    q.push(cur->left);
                }
                if(cur->right != NULL){
                    q.push(cur->right);
                }
                q.pop();
            }
            depth++;
        }
        return depth;
    }
};
// @lc code=end

