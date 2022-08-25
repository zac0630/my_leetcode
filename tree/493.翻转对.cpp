/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */

// @lc code=start
// #include "common.h"
class Solution {
private:
    int* temp;
    int count;
public:
    int reversePairs(vector<int>& nums) {
        count = 0;
        temp = new int[nums.size()];
        sort(nums, 0, nums.size()-1);
        return count;
    }
    void sort(vector<int>&nums, int lo,  int hi){
        if(lo == hi){
            return;
        }
        int mid = (lo + hi)/2;
        sort(nums, lo, mid);
        sort(nums, mid+1, hi);
        merge(nums, lo, mid, hi);
    }
    void merge(vector<int>& nums, int lo, int mid, int hi){
        for(int i = lo; i <= hi; i++){
            temp[i] = nums[i];
        }

        //对于nums[i]>2*nums[j]，完全可以通过双重循环遍历得到
        //优化，由于nums[i]>2*nums[j]，那么nums[i]>2*nums[j-1]必然成立
        //因此，第二重循环可以提前结束
        //以下，对每个nums[i]做判断
        int end = mid + 1;  //end从右半边的起始位置开始
        for(int i = lo; i <= mid; i++){
            while(end <= hi && (long)nums[i] > (long)2*nums[end]){
                end++;
            }
            count += end - (mid + 1);
        }

        int i = lo;
        int j = mid + 1;
        for(int p = lo; p <= hi; p++){
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

