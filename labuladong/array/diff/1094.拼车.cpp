/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001, 0);
        for (vector<int> &t: trips) {
            diff[t[1]] += t[0];
            diff[t[2]] -= t[0];
        }

        if (diff[0] > capacity) return false;
        for (int i = 1; i < 1001; i ++) {
            diff[i] += diff[i-1];
            if (diff[i] > capacity) return false;
        }
        return true;
    }
};
// @lc code=end

