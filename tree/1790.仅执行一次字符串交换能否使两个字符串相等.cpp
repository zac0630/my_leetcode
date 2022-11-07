/*
 * @lc app=leetcode.cn id=1790 lang=cpp
 *
 * [1790] 仅执行一次字符串交换能否使两个字符串相等
 */

// @lc code=start
// #include "common.h"
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0;
        int m = -1;
        int n = -1;
        int num = s1.length() > s2.length() ? s1.length() : s2.length();
        for(int i = 0; i < num; i++){
            if(s1[i] != s2[i]){
                count++;
                if(m == -1){
                    m = i;
                }
                else if( n == -1){
                    n = i;
                }
                if(count > 2)
                    return false;
            }
        }
        if(m == -1 || n == -1) return m == n;
        return s1[m] == s2[n] && s1[n] == s2[m];
    }
};
// @lc code=end

