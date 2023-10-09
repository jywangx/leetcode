/*
 * @lc app=leetcode.cn id=2578 lang=cpp
 *
 * [2578] 最小和分割
 */

// @lc code=start
class Solution {
public:
    int splitNum(int num) {
        vector<uint8_t> nums(10);
        for (int i = 0; i < 10 && num > 0; i ++) {
            nums[i] = num%10;
            num /= 10;
        }

        sort(nums.begin(), nums.end(), greater<uint8_t>());
        int res = 0;
        for (
            int i = 0, base = 1; 
            i < 10 && nums[i] > 0;
            base *= 10, i += 2
        ) {
            res += base *(nums[i] + nums[i+1]);
        }
        return res;
    }
};
// @lc code=end

