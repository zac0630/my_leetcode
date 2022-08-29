/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    long targetSum;
    long preSum;
    unordered_map<long, int> map;
    int count = 0;
public:
    int pathSum(TreeNode* root, int targetSum) {
        this->targetSum = targetSum;
        map.emplace(0, 1);
        //preSum表示的是路径到当前节点的前缀和，map也是当前路径
        //树与数组的区别就是有多条路径，那么在前序位置插入，在后续位置删除，
        //维护好preSum和map
        if(root==NULL)  return count;
        preSum = 0;
        help(root);
        return count;
    }
    void help(TreeNode* root){
        if(root == NULL)
            return;
        //前序位置
        preSum += root->val;
        //寻找在这之前的前缀和与preSum的差是否在map中
        if(map.count(preSum - targetSum)){
            count += map[preSum - targetSum];
        }
        //将当前前缀和加入map中
        if(map.count(preSum)){
            map[preSum]++;
        }
        else{
            map[preSum] = 1;
        }
        help(root->left);
        help(root->right);

        //后续位置维护preSum和map
        map[preSum]--;
        preSum -= root->val;
    }
};
// @lc code=end

