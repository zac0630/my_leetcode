/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
// #include "common.h"
class Solution {
//使用归并算法
private:
    int* temp;
public:
    vector<int> sortArray(vector<int>& nums) {
        temp = new int[nums.size()];
        sort(nums, 0, nums.size()-1);
        return nums;
    }
    //递归分解问题，排序左子树，排序右子树
    void sort(vector<int>& nums, int lo, int hi){
        // nums[0] = nums[2];
        if(lo == hi)
            return;
        int mid = (lo+hi)/2;
        sort(nums, lo, mid);
        sort(nums, mid+1, hi);
        merge(nums, lo, mid, hi);
    }
    void merge(vector<int>& nums, int lo, int mid, int hi){
        //将nums中[lo,hi]复制到temp中
        //然后从temp中复制数据到nums中
        for(int i = lo; i <= hi; i++){
            temp[i] = nums[i];
        }
        int i = lo;         //从左半边开始
        int j = mid + 1;    //从右半边开始
        for(int p = lo; p <= hi; p++){
            if(i == mid + 1){    //左半边已经复制完毕
                nums[p] = temp[j++];
            }
            else if(j == hi + 1){   //右半边复制完毕
                nums[p] = temp[i++];
            }
            else if(temp[i] > temp [j]){
                nums[p] = temp[j++];
            }
            else{
                nums[p] = temp[i++];
            }
        }
    }
};
// @lc code=end

