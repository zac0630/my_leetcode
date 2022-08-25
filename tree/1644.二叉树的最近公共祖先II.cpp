/*
 * @lc app=leetcode.cn id=1656 lang=cpp
 *
 * [1644] 二叉树的最近公共祖先II 会员专享
 * 输入是一颗不含重复值的二叉树，一个包含若干节点的列表，这些节点不一定存在于二叉树中
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
private:
    //由于p和q不一定存在于树中，记录p和q的真值
    bool foundP;
    bool foundQ;
public:
    TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        foundP = false;
        foundQ = false;
        TreeNode res = find(root, p.val, q.val);
        //如果p和q至少一个不存在，必不存在公共祖先
        if(!foundP || !foundQ){
            return NULL;
        }
        return res;
    }
    TreeNode find(TreeNode root, int val1, int val2){
        if(root == NULL)    return NULL;
        TreeNode* left = find(root.left, val1, val2);
        TreeNode* right = find(root.right, val1, val2);
        //case2 在root的左子树和右子树分别找到了p和q
        //root是公共祖先
        if(left != NULL && right != NULL)
            return root;
        //case 1
        if(root.val == val1 || root.val == val2){
            if(root.val == val1)    foundP = true;
            if(root.val == val2)    foundQ = true;
            return root;
        }
        return left != NULL ? left : right;
    }
};
// @lc code=end

