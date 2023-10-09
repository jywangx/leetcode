/*
 * @lc app=leetcode.cn id=2731 lang=cpp
 *
 * [2731] 移动机器人
 */

// @lc code=start
class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();
        int mod = 1e9+7;
        transform(s.begin(), s.end(), nums.begin(), nums.begin(), [&](char c, int num) {
            return (c == 'R') ? num + d : num - d;
        });
        sort(nums.begin(), nums.end());
        long long res = 0, temp = 0;
        for (long long i = 1; i < n; i ++) {
            long long a = nums[i], b = nums[i-1];
            temp += (i*(a - b))%mod;
            temp %= mod;
            res += temp;
            res %= mod;
        }

        return res;
    }
};
// @lc code=end

