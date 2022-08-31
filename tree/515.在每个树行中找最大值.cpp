/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
//思路一：层次遍历，在每一层都寻找最大值加入vector
//思路二：深度遍历，遍历时记录深度和值，加入map（树深，值），对同一深度的值做比较
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        int len = 0;
        TreeNode* cur = NULL;
        int maxSum;
        while(!q.empty()){
            len = q.size();
            maxSum = q.front()->val;
            for(int i = 0; i < len; i++){
                cur = q.front();
                //找到当前层的最大值
                if(cur->val > maxSum)
                    maxSum = cur->val;
                if(cur->left != NULL)
                    q.push(cur->left);
                if(cur->right != NULL)
                    q.push(cur->right);
                q.pop();
            }
            res.push_back(maxSum);
        }
        return res;
    }
};
// @lc code=end

