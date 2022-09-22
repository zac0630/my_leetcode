/*
 * @lc app=leetcode.cn id=933 lang=cpp
 *
 * [933] 最近的请求次数
 */

// @lc code=start
// #include "common.h"
class RecentCounter {
private:
    queue<int> q;
public:
    RecentCounter() {

    }
    
    int ping(int t) {
        q.push(t);
        while(t - q.front() > 3000)
            q.pop();
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end

