/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        else if (n == 1) return 1;
        int res;
        for (int lln = 0, ln = 1, i = 2; i <= n; i ++) {
            res = ln + lln;
            lln = ln;
            ln = res;
        }
        return res;
    }
};
// @lc code=end

