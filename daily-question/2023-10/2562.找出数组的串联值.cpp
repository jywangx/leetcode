/*
 * @lc app=leetcode.cn id=2562 lang=cpp
 *
 * [2562] 找出数组的串联值
 */

// @lc code=start
class Solution {
private:
    long long concVal(int num1, int num2) {
        long long res;
        for (res = 1; res <= num2; res *= 10);
        // printf("conc %d %d res=%d\n", num1, num2, res * num1 + num2);
        return res * num1 + num2;
    }
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int i, j;
        long long res = 0;
        for (i = 0, j = nums.size()-1; i < j; i ++, j --) {
            res += concVal(nums[i], nums[j]);
        }
        if (i == j) {
            res += nums[i];
        }
        return res;
    }
};
// @lc code=end

