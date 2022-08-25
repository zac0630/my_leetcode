/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
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
    unordered_map<string, int> memo;
    vector<TreeNode*> res;
public:
    //如何存储子树结构，以便与对比是否相等。
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        res.clear();
        traverse(root);
        return res;
    }
    //返回这颗子树的序列化结果，以字符串形式加分隔符
    string traverse(TreeNode* root){
        if(root == NULL)
            return "#";
        string leftTree = traverse(root->left);
        string rightTree = traverse(root->right);

        string subtree;
        subtree = leftTree + "," + rightTree + "," + to_string(root->val);
        if(memo[subtree] == 1) res.push_back(root);
        memo[subtree]++;
        return subtree;
    }
};
// @lc code=end

