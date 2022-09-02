/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
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
//思路一：层次遍历，能够拿到每一层的节点，当深入到第depth-1层时，借助辅助函数插入新节点
//思路二：深度遍历，遍历每一个节点，同时记录深度，当深度==depth时，开始插入新节点。
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* res = new TreeNode(val);
            res->left = root;
            return res;
        }
        int curDepth = 1;
        int curLen;
        TreeNode* cur;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            curLen = q.size();
            curDepth++;
            for(int i = 0; i < curLen; i++){
                cur = q.front();
                if(cur->left != NULL)   q.push(cur->left);
                if(cur->right != NULL)  q.push(cur->right);
                //给当前层的节点插入子节点
                if(curDepth == depth) insertTreeNode(cur, val);
                q.pop();
            }
            if(curDepth == depth) break;
        }
        return root;
    }
    void insertTreeNode(TreeNode* root, int val){
        TreeNode* leftNode = new TreeNode(val);
        TreeNode* rightNode = new TreeNode(val);
        leftNode->left = root->left;
        root->left = leftNode;
        rightNode->right = root->right;
        root->right = rightNode;
        return;
    }
};
// @lc code=end

