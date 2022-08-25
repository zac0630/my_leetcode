/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
//思路1 层次遍历 打印每一层的最后一个节点
//思路2 向右搜索 直到没有右孩子 继续将左孩子放入 向右搜索 直到到达叶子节点
class Solution {
private:
    vector<int> res;
    queue<TreeNode*> q;
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
            return res;
        q.push(root);
        while(!q.empty()){
            int curLen = q.size();
            TreeNode* cur;
            for(int i = 0; i < curLen; i++){
                cur = q.front();
                //这一层的最后节点加入res
                if(i == curLen - 1)
                    res.push_back(cur->val);
                if(cur->left != NULL)
                    q.push(cur->left);
                if(cur->right != NULL)
                    q.push(cur->right);
                q.pop();
            }
        }
        return res;
    }
/*     
    //无法满足左子树比右子树高的情况
    void traverse(TreeNode* root){
        //到达叶子节点
        if(root->left == root->right)
            return;
        //没到达
        if(root->right){
            res.push_back(root->right->val);
            traverse(root->right);
        } 
        else{
            res.push_back(root->left->val);
            traverse(root->left);
        } 
    }
*/
};
// @lc code=end

