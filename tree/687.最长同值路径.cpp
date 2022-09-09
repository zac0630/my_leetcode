/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
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
//无思路
class Solution {
private:
    int res;
public:
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL)    return 0;
        maxLen(root, root->val);
        return res;
    }
    //对于当前节点来说，需要知道其父节点的值，如果root的值和父节点的不相等，返回0
    //定义：计算以 root 为根的这棵二叉树中，从 root 开始值为 parentVal 的最长树枝长度
    int maxLen(TreeNode* root, int parentVal){
        if(root == NULL)    return 0;

        int leftLen = maxLen(root->left, root->val);
        int rightLen = maxLen(root->right, root->val);

        // 同值路径就是左右同值树枝长度之和
        res = max(res, leftLen + rightLen);

        // 如果 root 本身和上级值不同，那么整棵子树都不可能有同值树枝
        if(root->val != parentVal)
            return 0;

        // 实现函数的定义：
        // 以 root 为根的二叉树从 root 开始值为 parentVal 的最长树枝长度
        // 等于左右子树的最长树枝长度的最大值加上 root 节点本身
        return 1 + max(leftLen, rightLen);
    }
};
// @lc code=end

