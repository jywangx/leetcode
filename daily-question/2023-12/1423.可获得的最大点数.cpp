/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 *
 * [1423] 可获得的最大点数
 */

// @lc code=start
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> prefixSum(k+1, 0);
        vector<int> suffixSum(k+1, 0);
        for (int i = 0; i < k; i ++) {
            prefixSum[i+1] = prefixSum[i] + cardPoints[i];
            suffixSum[i+1] = suffixSum[i] + cardPoints[n-1-i];
        }
        int res = 0;
        for (int i = 0; i <= k; i ++) {
            res = max(res, prefixSum[i] + suffixSum[k-i]);
        }
        return res;
    }
};
// @lc code=end

