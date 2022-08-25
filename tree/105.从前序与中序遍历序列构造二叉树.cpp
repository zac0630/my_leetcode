/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
class Solution
{
private:
    unordered_map<int, int> valToIndex;
public:
    //存储inorder中 值到索引的映射
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            valToIndex[inorder[i]]= i;
        }
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode *build(vector<int> &preorder, int preStart, int preEnd,
                    vector<int> &inorder, int inStart, int inEnd)
    {
        if (preStart > preEnd)
            return NULL;

        //前序遍历的第一个就是根节点
        int rootVal = preorder[preStart];
        //构造根节点
        TreeNode *root = new TreeNode(rootVal);

        //用根节点将中序遍历分成两半
        //先找到根节点在中序遍历中的位置
        int index = valToIndex[rootVal];
        int leftTreeLen = index - inStart;
        //构建左子树，中序遍历的左半边
        root->left = build(preorder, preStart + 1, preStart + leftTreeLen, inorder, inStart, index - 1);
        //构建右子树
        root->right = build(preorder, preStart + leftTreeLen + 1, preEnd, inorder, index + 1, inEnd);
        return root;
    }
};
// @lc code=end
