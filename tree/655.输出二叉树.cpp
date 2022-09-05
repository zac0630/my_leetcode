/*
 * @lc app=leetcode.cn id=655 lang=cpp
 *
 * [655] 输出二叉树
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
//思路一：等价于将节点插入矩阵的坐标。行号是矩阵的树高，如何确定列号
//首先确定总高，子节点列号与根节点关系c-2^(height-r-1)和c-2^(height-r+1)
class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int height = calDepth(root);
        int m = height + 1;
        int n = (1 << m) - 1;
        //先构造出res
        vector<vector<string>> res(m, vector<string>(n, ""));
        traverse(res, root, 0, (n - 1)/2, height);
        return res;
    }
    int calDepth(TreeNode* root) {
        int h = 0;
        if (root->left) {
            h = max(h, calDepth(root->left) + 1);
        }
        if (root->right) {
            h = max(h, calDepth(root->right) + 1);
        }
        return h;
    }
    void traverse(vector<vector<string>>& res, TreeNode* root, int r, int c, const int& height){
        // if(root == NULL) return; 在这里判断是否为空返回是会出错的
        //当前节点应该做什么
        res[r][c] = to_string(root->val);
        if(root->left)
            traverse(res, root->left, r + 1, c - (1<<(height - r - 1)), height);
        if(root->right)
            traverse(res, root->right, r + 1, c + (1<<(height - r - 1)), height);
    }
};
// @lc code=end

