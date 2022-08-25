/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
    }
    //设置三个节点，当前节点root，min是当前root的取值下限，max是当前root的取值上限
    //一开始是NULL和NULL，表示-∞到+∞
    //root满足之后，结合左右子树的情况，约束需要变化再传到子树中去
    /*
    //关注当前节点与左右孩子的行为
    //当前结点root的左孩子root.left
    max = root.val；
    min = min;//最小值保持不变
    //当前结点root的右孩子root.right
    min = root.val，
    max = max;//最大值保持不变
    //左右孩子分别将root的min， max约束传递下来

    //min只有从根一直向左传递才会为null
    //max只有从根一直向右传递才会为null
    //中途只要变过方向约束条件都会变
    */
    bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max){
        if(root == NULL)
            return true;
        
        if(min != NULL && root->val <= min->val)
            return false;
        if(max != NULL && root->val >= max->val)
            return false;
        
        return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
    }
};
// @lc code=end

