/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
class Solution {
public:
    //flatten函数，将以root为根的数拉成一条链表
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        
        //利用定义分别拉平左右
        flatten(root->left);
        flatten(root->right);

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        //将左子树嫁接
        root->right = left;
        root->left = NULL;
        //找原先左子树的最右节点
        TreeNode* p = root;
        while(p->right != NULL){
            p = p->right;
        }
        //将右子树嫁接到原先左子树的最右节点
        p->right = right;
    }
};
// @lc code=end

