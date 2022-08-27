/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
// #include "common.h"
class Solution {
private:
    int* memo1 = NULL;
    int* memo2 = NULL;
    int n = 0;
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        n = nums.size() - 1;
        memo1 = new int[nums.size()];
        memo2 = new int[nums.size()];
        for(int i = 0; i <= n; i++){
            memo1[i] = -1;
            memo2[i] = -1;
        }
        return max(dp(nums, 0, n-1, memo1), dp(nums, 1, n, memo2));
    }
    //如何区分环形
    //首位房间不能同时被抢，要么都不被抢，
    //要么第一间房被抢，最后一间不被抢
    //要门最后一间被抢，第一间不被抢
    int dp(vector<int>& nums, int start, int end, int* memo){
        if(start > end)
            return 0;
        if(memo[start] != -1)
            return memo[start];
        int do_it = nums[start] + dp(nums, start + 2, end, memo);
        int not_do = dp(nums, start + 1 ,end, memo);
        int res = max(do_it, not_do);
        memo[start] = res;
        return res;
    }
};
// @lc code=end

