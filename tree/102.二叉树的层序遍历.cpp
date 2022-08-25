/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     if(root==NULL)
    //         return res;
    //     vector<TreeNode*> nodes;
    //     nodes.push_back(root);
    //     traverse(nodes);
    //     return res;
    // }
    // //递归方式
    // void traverse(vector<TreeNode*>& curLevelNodes){
    //     //如果当前节点列表为空，直接返回
    //     if(curLevelNodes.empty())
    //         return;
    //     //如果不为空，将curLevelNodes的值合并成vector加入res
    //     //同时将curLevelNodes的子节点保存起来，用作下一次递归
    //     vector<int> value;
    //     vector<TreeNode*> nextLevelNodes;
    //     for(TreeNode* node: curLevelNodes){
    //         value.push_back(node->val);
    //         if(node->left)
    //             nextLevelNodes.push_back(node->left);
    //         if(node->right)
    //             nextLevelNodes.push_back(node->right);
    //     }
    // 前序位置添加结果，可以得到自顶向下的层序遍历
    //     res.push_back(value);
    //     traverse(nextLevelNodes);
    // 后序位置添加结果，可以得到自底向上的层序遍历结果
    // res.add(nodeValues);      
    // }

    //迭代方式
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int curLen = q.size();
            vector<int> curLevel;
            curLevel.clear();
            for(int i = 0; i < curLen; i++){
                TreeNode* curNode = q.front();
                curLevel.push_back(curNode->val);
                if(curNode->left != NULL){
                    q.push(curNode->left);
                }
                if(curNode->right){
                    q.push(curNode->right);
                }
                q.pop();
            }
            res.push_back(curLevel);
        }
        return res;
    }
};
// @lc code=end

