/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
//第一种，遍历所有叶子节点，借助外部变量判断是否ture
class Solution {
public:
    //分解问题，判当前节点是不是叶子节点，是的话，判断大小
    //不是的话，递归进左右子树，同时将targetSum减去当前节点值
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return false;
        if(root->left == root->right && root->val == targetSum)
            return true;
        return hasPathSum(root->left, targetSum - root->val) ||
                hasPathSum(root->right, targetSum - root->val);
    }
};

//第二种遍历思路，前序加，后序减。
//需要借助外部变量
bool found = false;
int target;
int cur = 0;    //记录到当前节点的路径和

//sum表示到当前节点的路径和
void traverse(TreeNode* root){
    if(root == NULL){
        return;
    }
    cur += root->val;
    if(root->left == root->right)
        found = true;

    traverse(root->left);
    traverse(root->right);
    cur -= root->val;
}

bool hasPathSum(TreeNode* root, int targetSum) {
    if(root == NULL)
        return false;
    target = targetSum;
    traverse(root);
    return found;
}
// @lc code=end

