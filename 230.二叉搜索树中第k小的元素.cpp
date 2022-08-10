/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
private:
    int rank;
    int res;
public:
    int kthSmallest(TreeNode* root, int k) {
        rank = 0;
        res = 0;
        traverse(root, k);
        return res;
    }
    void traverse(TreeNode* root, int k){
        if(root == NULL){
            return;
        }
        traverse(root->left, k);
        rank++;
        if(k == rank){
            res = root->val;
            return;
        }
        traverse(root->right, k);

    }
};
// @lc code=end

