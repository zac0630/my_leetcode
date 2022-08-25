/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    unordered_map<int, int> valToIndex;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++){
            valToIndex[inorder[i]] = i;
        }
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }

    TreeNode* build(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd){
        if(postStart > postEnd){
            return NULL;
        }
        //构造根节点，根节点在后序遍历的末尾
        int rootVal = postorder[postEnd];
        int rootIndex = valToIndex[rootVal];
        TreeNode* root = new TreeNode(rootVal);

        //确定左子树的长度，以此来划分后序遍历
        int leftLen = rootIndex - inStart;

        root->left = build(inorder, inStart, rootIndex - 1, postorder, postStart, postStart + leftLen - 1);
        root->right = build(inorder, rootIndex + 1, inEnd, postorder, postStart + leftLen, postEnd-1);
        return root;
    }
};
// @lc code=end

