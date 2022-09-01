/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
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
//题解思路：在后序遍历位置去组装，组装需要左右子树的字符串
class Solution {
private:
    string res = "";
public:
    string tree2str(TreeNode* root) {
        // 基本的情况
        if(root == NULL)    return "";
        if(root->left == root->right)   return to_string(root->val);

        //递归生成左右子树的字符串
        string leftStr = tree2str(root->left);
        string rightStr = tree2str(root->right);

        //需要看出题目的要求，处理只有一边子树的情况
        //如果右子树为空
        if(root->left != NULL && root->right == NULL){
            //要求一：省略空的右子树
            return to_string(root->val) + "(" + leftStr + ")";
        }
        if(root->left == NULL && root->right != NULL){
            //要求二：不省略空的左子树
            return to_string(root->val) + "()" + "(" + rightStr + ")";
        }
        return to_string(root->val) + "(" + leftStr + ")" + "(" + rightStr + ")";

    }   

};
// @lc code=end

