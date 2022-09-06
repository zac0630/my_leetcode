/*
 * @lc app=leetcode.cn id=1104 lang=cpp
 *
 * [1104] 二叉树寻路
 */

// @lc code=start
// #include "common.h"
//思路一：无思路，计算根标号的数学关系，对称性。
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        while(label){
            ans.push_back(label);
            label = label / 2;
        }
        reverse(ans.begin(), ans.end());
        int l, r, deep = ans.size();
        //根据对称性调整节点标号
        for(int i = 0; i < deep; i++){
            if((deep & 1) != (i & 1))   continue;
            l = (1<<i);
            r = l + l - 1;
            ans[i] =  r - ans[i] + l;
        }
        return ans;
    }
};
// @lc code=end

