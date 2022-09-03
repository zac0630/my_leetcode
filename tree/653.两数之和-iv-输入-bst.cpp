/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
//思路一：两数之和特点，将k-val的值存入set中，遍历每个节点。但是这样没有利用BST的特性，如何利用二叉搜索树的特性
//思路二：利用BST得到中序遍历，再利用双指针解决两数之和问题
class Solution {
private:
    unordered_set<int> set;
    bool flag = false;
    int target = 0;
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL)    return false;
        if(root->left == root->right)   return false;
        this->target = k;
        traverse(root);
        return flag;
    }
    void traverse(TreeNode* root){
        if(root == NULL)    return;
        if(set.count(target - root->val)== 1)    flag = true;
        set.insert(root->val);

        traverse(root->left);
        traverse(root->right);
    }
};
// @lc code=end

