/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
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
//思路：递归得到子树和，计算curCount，加入map，更新maxCount和map
//map中存的是出现次数最多的子树元素和
//更新map情况：
class Solution {
private:
    int maxCount = 0;
    //存放 子树和 及 出现的次数
    unordered_map<int, int> map;
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        subTreeSum(root);
        for(auto iter = map.begin(); iter != map.end(); iter++){
            if(iter->second == maxCount){
                res.push_back(iter->first);
            }
        }
        return res;
        // auto iter = map.begin();
        // int maxCount = iter->second;
        // res.push_back(iter->first);
        // iter++;
        // //遍历map，得到次数的最大值
        // for(; iter != map.end(); iter++){
        //     if(iter->second == maxCount){
        //         res.push_back(iter->first);
        //     }
        //     else if(iter->second > maxCount){
        //         maxCount = iter->second;
        //         res.clear();
        //         res.push_back(iter->first);
        //     }
        // }
        // return res;
    }
    //遍历节点，将所有 子树元素和 加入map，
    //返回子树和
    int subTreeSum(TreeNode* root){
        if(root == NULL)
            return 0;
        int left = subTreeSum(root->left);
        int right = subTreeSum(root->right);
        int res = root->val + left + right;
        //在后序位置计算子树元素和，并更新map
        //如果map中没有出现过
        if(map.count(res)){
            map[res]++;
        }
        else{
            map.emplace(res, 1);
        }
        maxCount = max(maxCount, map[res]);
        return res;
    }
};
// @lc code=end

