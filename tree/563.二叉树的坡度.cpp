/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
//思路一：遍历，计算每个节点的子树和，得到每个节点的坡度加入外部变量vector，最终相加，
//思路二：直接定义计算子树和函数递归，在后序位置计算当前节点的坡度
class Solution {
private:
    int res = 0;
public:
    int findTilt(TreeNode* root) {
        treeSum(root);
        return res;
    }

    //是否需要一个函数计算子树和
    int treeSum(TreeNode* root){
        if(root == NULL)
            return 0;
        int left = treeSum(root->left);
        int right = treeSum(root->right);
        res += abs(left - right);
        return root->val + left + right;
    }
};

/* private:
    vector<int> res;
public:
    int findTilt(TreeNode* root) {
        int sum = 0;
        if(root == NULL)
            return sum;
        traverse(root);
        for(int i = 0; i < res.size(); i++){
            sum += res[i];
        }
        return sum;
    }
    void traverse(TreeNode* root){
        if(root == NULL)
            return;
        int left = treeSum(root->left);
        int right = treeSum(root->right);
        res.push_back(abs(left - right));
        traverse(root->left);
        traverse(root->right);
    }

    //是否需要一个函数计算子树和
    int treeSum(TreeNode* root){
        if(root == NULL)
            return 0;
        return root->val + treeSum(root->left) + treeSum(root->right);
    } */
// @lc code=end

