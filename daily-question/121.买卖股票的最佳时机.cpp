/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prev_min = INT_MAX, max_p = 0;
        for (int &n : prices) {
            max_p = max(max_p, n-prev_min);
            prev_min = min(prev_min, n);
        }
        return max_p;
    }
};
// @lc code=end

