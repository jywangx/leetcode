/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0, gap = 1; i + gap < n; i ++) {
            if (nums[i] == 0) {
                for (; i+gap < n && nums[i+gap] == 0; gap ++);
                if (i+gap < n) {
                    swap(nums[i], nums[i+gap]);
                }
            }
        }
    }
};
// @lc code=end

