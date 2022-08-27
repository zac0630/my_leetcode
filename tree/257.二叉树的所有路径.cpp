/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
vector<string> res;
string  cur;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL)
            return res;
        helper(root, "");
        return res;        
    }
    void helper(TreeNode* root, string path){
        if(root != NULL){
            path += to_string(root->val);
            if(root->left == root->right){
                res.push_back(path);
            }
            else{
                path += "->";
                helper(root->left, path);
                helper(root->right, path);
            }
        }
    }
};
// @lc code=end

