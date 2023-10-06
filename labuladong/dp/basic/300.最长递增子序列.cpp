/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, INT_MIN);
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
};
// @lc code=end

