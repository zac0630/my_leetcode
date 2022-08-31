/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
//思路一：遍历结束+unordermap存入
//思路二：遍历过程中，能够记录信息，如何利用BST特性！！！
//利用中序遍历有序，设置prev指针，根据prev和root的关系，更新当前元素的重复次数和全局的最长相同序列长度
class Solution {
private:
    vector<int> mode;
    // 当前元素的重复次数
    int curCount;
    // 全局的最长相同序列长度
    int maxCount;
    TreeNode* prev = NULL;
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        traverse(root);
        for(int i = 0; i < mode.size(); i++){
            res.push_back(mode[i]);
        }
        return res;
    }
    void traverse(TreeNode* root){
        if(root == NULL)
            return;
        traverse(root->left);
        //中序位置
        //prev为空，代表中序遍历刚刚开始
        if(prev == NULL){
            curCount = 1;
            maxCount = 1;
            mode.push_back(root->val);
        }
        else{
            //如果前一个元素和root值相等
            if(prev->val == root->val){
                curCount++;
                //需要更新众数
                if(curCount > maxCount){
                    maxCount = curCount;
                    mode.clear();
                    mode.push_back(root->val);
                }
                else if(curCount == maxCount){
                    mode.push_back(root->val);
                }
            }
            //如果和前一个元素不相等，设置curCount=1
            if(prev->val != root->val){
                curCount = 1;
                if(curCount == maxCount){
                    mode.push_back(root->val);
                }
            }
        }
        prev = root;
        traverse(root->right);
    }
};
// @lc code=end

