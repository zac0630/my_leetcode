/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL){
            return res;
        }
        vector<TreeNode*> curLevelNodes;
        curLevelNodes.push_back(root);
        traverse(curLevelNodes);
        return res;
    }
    void traverse(vector<TreeNode*> curLevelNodes){
        if(curLevelNodes.empty())
            return;
        //当前层有节点，需要将其加入nextLevelNodes
        vector<TreeNode*> nextLevelNodes;
        //保存当前节点的值
        vector<int> values;
        for(TreeNode* node: curLevelNodes){
            values.push_back(node->val);
            if(node->left != NULL)
                nextLevelNodes.push_back(node->left);
            if(node->right != NULL)
                nextLevelNodes.push_back(node->right);
        }
        traverse(nextLevelNodes);
        res.push_back(values);
    }
};
// @lc code=end

