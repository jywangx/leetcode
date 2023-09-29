/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0, j = numbers.size() - 1; i < j;) {
            if (numbers[i] + numbers[j] == target) {
                return {i + 1, j + 1};
            } else if (numbers[i] + numbers[j] < target) {
                i ++;
            } else {
                j --;
            }
        }
        return {-1, -1};
    }
};
// @lc code=end

