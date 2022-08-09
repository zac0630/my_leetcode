/*
 * @lc app=leetcode.cn id=327 lang=cpp
 *
 * [327] 区间和的个数
 */

// @lc code=start
// #include "common.h"
class Solution {
private:
    long* temp;
    int count;
    int lower;
    int upper;
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        this->lower = lower;
        this->upper = upper;
        //构造前缀和数组
        long* preSum = new long[nums.size()+1];
        temp = new long[nums.size()+1];
        for(int i = 0; i < nums.size(); i ++){
            preSum[i+1] = (long)nums[i] + preSum[i];
        }
        sort(preSum, 0, nums.size());
        return count;
    }

    void sort(long* nums, int lo, int hi){
        if(lo == hi){
            return;
        }

        int mid = (lo + hi) / 2;
        sort(nums, lo, mid);
        sort(nums, mid + 1, hi);
        merge(nums, lo, mid, hi);
        return;
    }

    void merge(long* nums, int lo, int mid, int hi){
        //先复制
        for(int i = lo; i <= hi; i++){
            temp[i] = nums[i];
        }

        //如何根据左右有序数组计算得到区间和在(lower upper)之间的区间个数
        // 维护左闭右开区间 [start, end) 中的元素和 nums[i] 的差在 [lower, upper] 中
        int start = mid + 1;
        int end = mid + 1;
        for(int i = lo; i <= mid; i ++){
            while(start <= hi && nums[start] - nums[i] < lower){
                start++;
            }
            while(end <= hi && nums[end] - nums[i] <= upper){
                end++;
            }
            count += end - start;
        }

        //再双指针排序
        int i = lo;
        int j = mid + 1;
        for(int p = lo; p <= hi; p ++){
            if(i == mid + 1){
                nums[p] = temp[j++];
            }
            else if(j == hi + 1){
                nums[p] = temp[i++];
            }
            else if(temp[i] > temp[j]){
                nums[p] = temp[j++];
            }
            else{
                nums[p] = temp[i++];
            }
        }
    }
};
// @lc code=end

