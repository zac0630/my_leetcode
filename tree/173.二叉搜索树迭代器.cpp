/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator {
private:
    // 模拟递归栈
    stack<TreeNode*> stk;
    // 左侧树枝一撸到底
    void pushLeftBrach(TreeNode* p){
        while(p != NULL){
            stk.push(p);
            p = p->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushLeftBrach(root);
    }
    
    int next() {
        TreeNode* p = stk.top();
        stk.pop();
        pushLeftBrach(p->right);
        return p->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

