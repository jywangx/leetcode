/*
 * @lc app=leetcode.cn id=1155 lang=cpp
 *
 * [1155] 掷骰子等于目标和的方法数
 */

// @lc code=start
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i ++) {
            for (int j = target-k*(n-i+1); j <= target; j ++) {
                for (int x = 1; x <= k; x ++) {
                    if (j-x >= 0) {
                        dp[i][j] += dp[i-1][j-x];
                        dp[i][j] = dp[i][j]%((int)1e9+7);
                    }
                }
            }
        }
        return dp[n][target];
    }
};
// @lc code=end

