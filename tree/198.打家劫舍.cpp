/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
// #include "common.h"
class Solution {
private:
    unordered_map<int, int> memo;
    int size = 0;
public:
    int rob(vector<int>& nums) {
        size = nums.size() - 1;
        return helper(nums, 0);
    }
    int helper(vector<int>& nums, int index){
        if(index > size)
            return 0;
        if(memo.count(index) != 0){
            return memo[index];
        }
        int do_it = nums[index] + helper(nums, index + 2);
        int not_do = helper(nums, index + 1);
        int res = max(do_it, not_do);
        memo.emplace(index, res);
        return res;
    }
};
// @lc code=end

