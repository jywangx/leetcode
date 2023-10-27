/*
 * @lc app=leetcode.cn id=2520 lang=cpp
 *
 * [2520] 统计能整除数字的位数
 */

// @lc code=start
class Solution {
public:
    int countDigits(int num) {
        int res = 0;
        for (int x = num; x > 0; x /= 10) {
            int d = x % 10;
            if (num % d == 0) {
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end

