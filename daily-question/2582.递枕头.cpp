/*
 * @lc app=leetcode.cn id=2582 lang=cpp
 *
 * [2582] 递枕头
 */

// @lc code=start
class Solution {
public:
    int passThePillow(int n, int time) {
        int i = time % (2*(n-1));
        if (i < n) return i+1;
        else return 2*n-1-i;
    }
};
// @lc code=end

