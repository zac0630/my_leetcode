/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
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
    unordered_map<int, int> valToIndex;
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i = 0; i < postorder.size(); i++)
            valToIndex[postorder[i]] = i;
        return build(preorder, 0, preorder.size()-1, postorder, 0, postorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& postorder, int postStart, int postEnd){
        if(preStart > preEnd)
            return NULL;
        
        if(preStart == preEnd)
            return new TreeNode(preorder[preStart]);
        
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        //默认前序遍历根节点后的第一个节点是左子树的根节点
        //但是左子树是可能为空的，因此有多种可能
        int leftRootVal = preorder[preStart+1];
        int index = valToIndex[leftRootVal];
        int leftLen = index - postStart + 1;

        root->left = build(preorder, preStart+1, preStart+leftLen, postorder, postStart, index);
        root->right = build(preorder, preStart+leftLen+1, preEnd, postorder, index+1, postEnd-1);
        return root;
    }
};
// @lc code=end

