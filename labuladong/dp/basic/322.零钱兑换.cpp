/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 0);
        for (int i = 1; i <= amount; i ++) {
            int min = INT_MAX;
            for (int j = 0; j < coins.size(); j ++) {
                if (i - coins[j] >= 0 && dp[i-coins[j]] != -1 && dp[i-coins[j]] < min) {
                    min = dp[i-coins[j]];
                }
            }
            dp[i] = min == INT_MAX ? -1 : min + 1;
        }
        return dp[amount];
    }
};
// @lc code=end

