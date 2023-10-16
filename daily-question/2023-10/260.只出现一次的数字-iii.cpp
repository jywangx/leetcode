/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorRes = 0;
        for (int &num: nums) {
            xorRes ^= num;
        }
        int mask = 1;
        while ((xorRes & mask) == 0) {
            mask <<= 1;
        }
        int a = 0, b = 0;
        for (int &num: nums) {
            if (num & mask) {
                a ^= num;
            } else {
                b ^= num;
            }
        }
        return vector<int>{a, b};
    }
};
// @lc code=end

