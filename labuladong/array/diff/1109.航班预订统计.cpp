/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n, 0);

        for (vector<int> &b: bookings) {
            diff[b[0]-1] += b[2];
            if (b[1] < n) diff[b[1]] -= b[2];
        }

        for (int i = 1; i < n; i ++) {
            diff[i] += diff[i-1];
        }
        return diff;
    }
};
// @lc code=end

