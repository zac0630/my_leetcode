/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
// #include "common.h"
//思路一：递归
//思路二：动态规划
class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1)
            return n;
        int dp_i_1 = 0; int dp_i_2 = 1;
        int dp_i;
        for (int i = 2; i <= n; i++)
        {
            dp_i = dp_i_1 + dp_i_2;
            dp_i_1 = dp_i_2;
            dp_i_2 = dp_i;
        }
        return dp_i;
    }
};
// @lc code=end

