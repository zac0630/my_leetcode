/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
// #include "common.h"
//套用归并排序
//定义结构体，用来存放每个元素及其在原始数组 nums 中的索引
//因为在归并排序时，当前节点结束归并后，元素索引会发生变化（即变为升序，但是不影响和兄弟节点的count计数）
struct Pair
{
    int val;
    int id;
};

class Solution {
private:
    Pair*   temp;
    int*    count;
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        temp = new Pair[n];
        count = new int[n];
        Pair* arr = new Pair[n];
        for(int i = 0; i < n; i++){
            arr[i] = Pair{nums[i], i};
            count[i] = 0;
        }
        sort(arr, 0, nums.size()-1);

        vector<int> res;
        for(int i = 0; i < n; i++){
            res.push_back(count[i]);
        }
        return res;
    }
    void sort(Pair* arr, int lo, int hi){
        if(lo == hi)
            return;
        int mid = (lo + hi)/2;
        sort(arr, lo, mid);
        sort(arr, mid + 1, hi);
        merge(arr, lo, mid, hi);
    }
    void merge(Pair* arr, int lo, int mid, int hi){
        for(int i = lo; i <= hi; i++){
            temp[i] = arr[i];
        }
        int i = lo;
        int j = mid + 1;
        for(int p = lo; p <= hi; p++){
            if(i == mid + 1){
                arr[p] = temp[j++];
            }
            else if(j == hi + 1){   //右半边到头了，说明此时右侧元素都比当前temp[i].val小
                arr[p] = temp[i++];
                count[arr[p].id] += j - mid - 1;
            }
            else if(temp[i].val > temp[j].val){
                arr[p] = temp[j++];
            }
            else{
                arr[p] = temp[i++];
                count[arr[p].id] += j - mid - 1;
            }
        }
    }
};
// @lc code=end

