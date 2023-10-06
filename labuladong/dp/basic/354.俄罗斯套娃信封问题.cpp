/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, INT_MIN);
        int max_len = 0;
        for (int &num : nums) {
            if (num > dp[max_len]) {
                max_len ++;
                dp[max_len] = num;
            } else {
                int left = 1, right = max_len;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (dp[mid] < num) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                dp[left] = num;
            }
        }
        return max_len;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        // 按宽度升序排列，如果宽度一样，则按高度降序排列
        sort(envelopes.begin(), envelopes.end(), 
            [](vector<int>& a, vector<int>& b) {
                return ((a[0] == b[0]) ? (a[1] > b[1]) : (a[0] < b[0]));
            });
        for (int i = 0; i < n; i++)
            printf("%d %d\n", envelopes[i][0], envelopes[i][1]);
        // 对高度数组寻找 LIS
        vector<int> height(n);
        for (int i = 0; i < n; i++)
            height[i] = envelopes[i][1];

        return lengthOfLIS(height);
    }
};
// @lc code=end

