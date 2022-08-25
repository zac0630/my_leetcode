/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
/* 
思考顺序：高度平衡，说明根节点是nums数组中间位置的数
从而想到使用lo hi来控制边界，构造中间位置的数为root
从而根据[lo, mid-1]和[mid+1, hi]来构造子树
总结，二叉树的构造问题，构造根节点，然后构建左右子树。
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())
            return NULL;
        return build(nums, 0, nums.size()-1);
    }
    //返回nums中从lo到hi构造成的二叉搜索树
    TreeNode* build(vector<int> nums, int lo, int hi){
        if(lo > hi)
            return NULL;
        int mid = (lo + hi) / 2;
        //构造根节点
        TreeNode* root = new TreeNode(nums[mid]);
        //构造左右子树
        root->left = build(nums, lo, mid - 1);
        root->right = build(nums, mid + 1, hi);
        return root;
    }
};
// @lc code=end

