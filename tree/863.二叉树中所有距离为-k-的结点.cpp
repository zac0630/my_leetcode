/*
 * @lc app=leetcode.cn id=863 lang=cpp
 *
 * [863] 二叉树中所有距离为 K 的结点
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// #include "common.h"
//无思路，如何向父节点传播
//思路：把二叉树变成一幅「图」
class Solution {
private:
    //依题意，每个节点的值不同，可以用val代替本节点
    unordered_map<int, TreeNode*> parent;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        //遍历所有节点，记录每个节点的父节点
        traverse(root, NULL);
        //二叉树的层次遍历，不仅向左右节点传播，还要向父节点传播
        queue<TreeNode*> q;
        unordered_set<int> visited;     //记录已经访问过的节点
        int depth = 0;

        q.push(target);
        visited.emplace(target->val);   //作用
        while(!q.empty()){
            int curLevel = q.size();
            for(int i = 0; i < curLevel; i++){
                TreeNode* curNode = q.front();
                if(depth == k){
                    res.push_back(curNode->val);
                }
                if(curNode->left != NULL && visited.count(curNode->left->val) == 0){
                    q.push(curNode->left);
                    visited.emplace(curNode->left->val);
                }
                if(curNode->right != NULL && visited.count(curNode->right->val) == 0){
                    q.push(curNode->right);
                    visited.emplace(curNode->right->val);
                }
                if(parent[curNode->val] != NULL && visited.count(parent[curNode->val]->val) == 0){
                    q.push(parent[curNode->val]);
                    visited.emplace(parent[curNode->val]->val);
                }
                q.pop();
            }
            depth++;
        }
        return res;
    }
    //遍历二叉树的同时，保存每个节点的父节点
    void traverse(TreeNode* root, TreeNode* parentNode){
        if(root == NULL)    return;
        parent.emplace(root->val, parentNode);
        traverse(root->left, root);
        traverse(root->right, root);
    }
};
// @lc code=end

