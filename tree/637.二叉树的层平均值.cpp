/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
//思路一：层次遍历
//思路二：深度遍历，但是不知道某一层一共有多少个节点
class Solution {
private:
    vector<double> res;
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        int curLen;
        TreeNode* cur = NULL;
        double sum = 0;
        while(!q.empty()){
            curLen = q.size();
            sum = 0;
            for(int i = 0; i < curLen; i++){
                cur = q.front();
                sum += cur->val;
                if(cur->left != NULL) q.push(cur->left);
                if(cur->right != NULL) q.push(cur->right);
                q.pop();
            }
            res.push_back(sum/curLen);
        }
        return res;
    }
};
// @lc code=end

