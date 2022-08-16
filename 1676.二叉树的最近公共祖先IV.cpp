/*
 * @lc app=leetcode.cn id=1656 lang=cpp
 *
 * [1656] 二叉树的最近公共祖先IV 会员专享
 * 输入是一颗不含重复值的二叉树，一个包含若干节点的列表，这些节点必存在于二叉树中
 * 计算这些节点的最近公共祖先
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
#include "common.h"
class Solution {
public: 
    TreeNode lowestCommonAncestor(TreeNode root, TreeNode[] nodes) {
        hash_set<int> values;
        for(TreeNode node : nodes){
            values.add(node.val);
        }
        return find(root, values);
    }
    TreeNode find(TreeNode root, hash_set<int> values){
        if(root == NULL)    return NULL;
        //case1 p或者q在一条连线上
        if(values.contains(root.val))
            return root;

        TreeNode* left = find(root->left, values);
        TreeNode* right = find(root->right, values);
        //case2 在root的左子树和右子树分别找到了p和q
        //root是公共祖先
        if(left != NULL && right != NULL)
            return root;
        
        return left != NULL ? left : right;
    }
};
// @lc code=end

