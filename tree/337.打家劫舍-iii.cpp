/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    unordered_map<TreeNode*, int> memo;
public:
    int rob(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(memo.count(root) != 0)
            return memo[root];
        int do_it = root->val
                + (root->left == NULL ? 0 : rob(root->left->left) + rob(root->left->right))
                + (root->right == NULL ? 0 : rob(root->right->left) + rob(root->right->right));
        int not_do = rob(root->left) + rob(root->right);

        int res = max(do_it, not_do);

        memo.emplace(root, res);
        return res;
    }
    // //返回以root为根能得到的最大值
    // int help(TreeNode* root){
    //     if(root == NULL)
    //         return 0;
    //     //第一种情况，选择root的值。
    //     //那么root的孩子不能再选，只能选孙子节点，而且是全选
    //     int sum1 = root->val
    //             + (root->left == NULL ? 0 : help(root->left->left) + help(root->left->right))
    //             + (root->right == NULL ? 0 : help(root->right->left) + help(root->right->right));

    //     //第二种情况，不选择root的值，全选孩子节点
    //     int sum2 = help(root->left) + help(root->right);
    //     return sum1 > sum2 ? sum1 : sum2;
    // }
};
// @lc code=end

