/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
//思路一：对左子树的节点来说，有左孩子范围2^h，无左孩子有右孩子，范围2^h - 1
//对右子树的节点来说，有右孩子范围2^h，无右孩子有左孩子，范围-2^h - 1
//思路二：思路一错误，通过父节点的编号计算得出左右子节点的编号，假设父节点的编号是 x，左子节点就是 2 * x，右子节点就是 2 * x + 1。
class Solution {
private:
    //在递归时记录最大值
    unsigned long long res = 1;
    //递归时，记录每一层的最左节点的编号
    vector<unsigned long long> firstId;
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        traverse(root, 1, 1);
        return (int)res;
    }
    void traverse(TreeNode* root, unsigned long long id, int h){
        if(root == NULL) return;
        if(firstId.size() == h - 1){
            firstId.push_back(id);
        }
        else{
            //索引是h-1
            res = max(res, id - firstId[h-1] + 1);
        }
        traverse(root->left, 2 * id, h + 1);
        traverse(root->right, 2 * id + 1, h + 1);
    }
};
// @lc code=end

