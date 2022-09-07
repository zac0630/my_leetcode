/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
class Solution {
private:
    int low;
    int high;
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        this->low = low;
        this->high = high;
        return traverse(root);
    }
    //返回剪枝后的根节点
    //疑问，什么时候用递归去处理子问题？
    TreeNode* traverse(TreeNode* root){
        if(root == NULL)    return NULL;

        //情况一：删除 root 节点本身和 root 的左子树
        if(root->val < low){
            // 直接返回 root.right
            // 等于删除 root 以及 root 的左子树
            return traverse(root->right);
        }
        //情况二：删除 root 节点本身和 root 的右子树
        if(root->val > high){
            return traverse(root->left);
        }
        //情况三：当前节点符合要求，啥也不做，递归进左右节点
        root->left = traverse(root->left);
        root->right = traverse(root->right);
        return root;
    }
};
// @lc code=end

