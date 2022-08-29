/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
// #include "common.h"
//前缀和技巧+hash表
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map.emplace(0, 1);
        //计算前缀和
        // int* sum = new int[nums.size()];
        // sum[0] = nums[0];
        // for(int i = 1; i < nums.size(); i++){
        //     sum[i] = sum[i-1] + nums[i];
        // }
        int rs = 0;
        int preSum = 0;
        for(int i = 0; i < nums.size(); i++){
            preSum += nums[i];
            int target = preSum - k;
            //寻找在[0,i-1]中的前序和
            if(map.count(target)){
                rs += map[target];
            }
            //维护i的前序和
            //如果map中有target，则map[preSum]++
            //如果没有target， 则将(preSum, 1)put进去
            if(map[preSum]){
                map[preSum]++;
            }
            else{
                map[preSum] = 1;
                // map.emplace(sum[i], 1);
            }
        }
        return rs;
    }
};
// @lc code=end

