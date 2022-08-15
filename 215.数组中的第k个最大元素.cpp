/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
// #include "common.h"
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int lo = 0;
        int hi = nums.size()-1;
        //转化为排名第k的元素
        k = nums.size() - k;
        while(lo <= hi){
            int p = position(nums, lo, hi);
            if(p < k){
                lo = p + 1;
            }
            else if(p > k){
                hi = p - 1;
            }
            else{
                return nums[p];
            }
        }
        return -1;
    }
    int position(vector<int>&nums, int lo, int hi){
        int val = nums[lo];
        //边界维护
        //[lo,i) <= pos (j, hi] > pos
        //当i > j结束循环时，保证区间[lo, hi]都被覆盖
        int i = lo + 1;
        int j = hi;
        while(i <= j){
            while(i < hi && nums[i] <= val) i++;
            while(j > lo && nums[j] > val) j--;
            if(i >= j)  break;
            swap(nums, i, j);
        }
        swap(nums, lo, j);
        return j;
    }
    void swap(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        return;
    }
};
// @lc code=end

