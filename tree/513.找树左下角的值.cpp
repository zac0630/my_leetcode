/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
//思路一：遍历，将左节点的值和树深加入map
//思路二：遍历时判断depth是否是maxDepth，利用到最大深度时第一次遇到的节点就是左下角的节点
class Solution {
private:
    TreeNode* res;
    int maxDepth = 0;
    int depth = 0;
public:
    int findBottomLeftValue(TreeNode* root) {
        if(root == NULL)
            return 0;
        traverse(root);
        return res->val;
    }
    void traverse(TreeNode* root){
        if(root == NULL)
            return;
        depth++;
        if(depth > maxDepth){
            // 到最大深度时第一次遇到的节点就是左下角的节点
            maxDepth = depth;
            res = root;
        }
        traverse(root->left);
        traverse(root->right);
        depth--;
    }
};
/* private:
    unordered_map<int, int> map;
    int maxDepth = 0;
public:
    int findBottomLeftValue(TreeNode* root) {
        if(root == NULL)
            return 0;
        traverse(root, 0);
        return map[maxDepth];
    }
    //加入形参depth，在每一节点遍历时能够得到它的高度
    void traverse(TreeNode* root, int depth){
        if(root == NULL)
            return;
        depth++;
        maxDepth = max(maxDepth, depth);
        //如果左节点为空，说明是左节点，同时记录该节点的值
        if(root->left == NULL){
            map.emplace(depth, root->val);
        }
        traverse(root->left, depth);
        traverse(root->right, depth);
    } */
// @lc code=end

