/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
private:
    vector<vector<int>> res;
    int cur = 0;
    vector<int> temp;
    int targetSum = 0;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return res;
        this->targetSum = targetSum;
        traverse(root);
        return res;
    }
    void traverse(TreeNode* root){
        if(root == NULL)
            return;
        //前序位置 记录路径和
        temp.push_back(root->val);
        cur += root->val;

        if(root->left == root->right && cur == this->targetSum){
            res.push_back(temp);
        }
        traverse(root->left);
        traverse(root->right);
        
        cur -= root->val;
        temp.pop_back();
    }
};
// @lc code=end

