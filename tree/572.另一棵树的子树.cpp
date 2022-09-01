/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
//思路一：遍历每个节点，当节点值与subRoot的相同时，判断这两颗树是不是相同，借助外部变量和辅助函数
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //这两种写法是不一样的
        //写法一能返回真假，当root为空，但是subRoot还有节点时，说明不相同
        //写法二只会返回真
        if(root == NULL)
            return subRoot == NULL;
        // if(root == subRoot)
        //     return true;
        if(isSameTree(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    bool isSameTree(TreeNode* p, TreeNode* q){
        //将四种情况列清楚
        //p==q，说明同为空节点
        if(p == q)
            return true;
        //有一个不为空
        if(p == NULL || q == NULL)
            return false;
        //两个节点都存在
        if(p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
// @lc code=end

