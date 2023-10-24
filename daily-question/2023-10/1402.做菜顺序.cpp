/*
 * @lc app=leetcode.cn id=1402 lang=cpp
 *
 * [1402] 做菜顺序
 */

// @lc code=start
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());
        vector<int> preSum(n+1);
        int res = 0;
        for (int i = 0; i < n; i ++) {
            preSum[i] = satisfaction[i] + (i > 0 ? preSum[i-1] : 0);
            if (preSum[i] <= 0) break;
            res += preSum[i];
        }
        return res;
    }
};
// @lc code=end

