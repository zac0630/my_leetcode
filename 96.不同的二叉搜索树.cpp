/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
// #include "common.h"
class Solution {
private:
    //备忘录
    int** memo;
public:
    int numTrees(int n) {
        memo = new int*[n+1];
        for(int i = 0; i < n + 1; i++){
            memo[i] = new int[n+1];
        }
        for(int i = 0; i < n + 1; i++){
            for(int j = 0; j < n + 1; j++){
                memo[i][j] = 0;
            }
        }
        
        return count(1, n);
    }
    //定义闭区间[lo, hi]的数字能组成count(lo, hi)种BST
    int count(int lo, int hi){
        if(lo > hi) return 1;
        int res = 0;

        if(memo[lo][hi] != 0){
            return memo[lo][hi];
        }

        for(int i = lo; i <= hi; i++){
            int left = count(lo, i - 1);
            int right = count(i + 1, hi);
            res += left * right;
        }
        //将结果存入备忘录
        memo[lo][hi] = res;
        return res;
    }
};
// @lc code=end

