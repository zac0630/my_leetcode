/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    long res = 0;
public:
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return res;
        vector<int> path;
        traverse(root, path);
        return res;
    }
    void traverse(TreeNode* root, vector<int>& path){
        if(root == NULL){
            return;
        }
        path.push_back(root->val);
        //一定要在前序位置判断当前节点是否是叶子节点！！！技巧
        if(root->left == root->right){
            res += calVector(path);
        }
        traverse(root->left, path);
        traverse(root->right, path);

        path.pop_back();
    }
    long calVector(vector<int>& path){
        long sum = 0;
        for(int i = path.size() - 1; i >= 0; i--){
            sum += path[i] * pow(10, path.size() - 1 - i);
        return sum;
    }
};
// @lc code=end

