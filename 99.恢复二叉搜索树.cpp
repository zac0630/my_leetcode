/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* pre = new TreeNode(0x80000000);
public:
    void recoverTree(TreeNode* root) {
        //记录前一个节点的值
        inorderTraverse(root);
        //交换两节点值
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
        return;
    }
    //二叉搜索树的中序遍历是有序的，找到破坏顺序的两个节点，交换他们
    void inorderTraverse(TreeNode* root){
        if(root == NULL){
            return;
        }
        inorderTraverse(root->left);
        //不符合升序的话
        if(pre->val > root->val){
            if(first == NULL){
                first = pre;
            }
            //第二个错位的节点是root不是pre
            second = root;
        }
        //下一个位置
        pre = root;
        inorderTraverse(root->right);
        return;
    }
};
// @lc code=end

