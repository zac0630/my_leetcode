/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty())
            return NULL;
        // if(nums.size() == 1)
        //     return TreeNode(nums[0]);
        //找到最大的数，创建根节点
        int maxVal = -1;
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxVal) {
                maxVal = nums[i];
                index = i;
            }
        }
        TreeNode *root = new TreeNode(nums[index]);

        vector<int> leftNums;
        vector<int> rightNums;
        leftNums.assign(nums.begin(), nums.begin()+index);
        rightNums.assign(nums.begin()+index+1, nums.end());

        root->left = constructMaximumBinaryTree(leftNums);
        root->right = constructMaximumBinaryTree(rightNums);
        return root;
    }
};
// @lc code=end

/* 主函数 */
// TreeNode* constructMaximumBinaryTree(int[] nums) {
//     return build(nums, 0, nums.length - 1);
// }

// // 定义：将 nums[lo..hi] 构造成符合条件的树，返回根节点
// TreeNode* build(int[] nums, int lo, int hi) {
//     // base case
//     if (lo > hi) {
//         return null;
//     }

//     // 找到数组中的最大值和对应的索引
//     int index = -1, maxVal = Integer.MIN_VALUE;
//     for (int i = lo; i <= hi; i++) {
//         if (maxVal < nums[i]) {
//             index = i;
//             maxVal = nums[i];
//         }
//     }

//     // 先构造出根节点
//     TreeNode* root = new TreeNode(maxVal);
//     // 递归调用构造左右子树
//     root->left = build(nums, lo, index - 1);
//     root->right = build(nums, index + 1, hi);
    
//     return root;
// }
