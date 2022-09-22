/*
 * @lc app=leetcode.cn id=988 lang=cpp
 *
 * [988] 从叶结点开始的最小字符串
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
//字符串操作，翻转，裁剪
//无法将题意和二叉树遍历模板相结合
class Solution {
private:
    string res = "";
    string path = "";   //遍历过程中维护的路径，即每个节点可以通过path找到去往根节点的路径
public:
    string smallestFromLeaf(TreeNode* root) {
        traverse(root);
        return res;
    }
    void traverse(TreeNode* root){
        if(root == NULL)
            return;
        path.push_back('a' + root->val);

        //当找到根节点时，作判断
        if(root->left == root->right){
            //翻转
            string curr = path;
            reverse(curr.begin(), curr.end());
            if(res.empty() || curr < res)
                res = curr;
        }

        traverse(root->left);
        traverse(root->right);
        path.pop_back();
    }
};
// @lc code=end

