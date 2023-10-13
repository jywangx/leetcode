/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        vector<int> sums(n+1, 0);
        unordered_map<int, int> numCnt;
        numCnt[0] = 1;
        for (int i = 0; i < n; i ++) {
            sums[i+1] = sums[i] + nums[i];
            if (numCnt.find(sums[i+1] - k) != numCnt.end()) {
                res += numCnt[sums[i+1] - k];
            }
            if (numCnt.find(sums[i+1]) == numCnt.end()) {
                numCnt[sums[i+1]] = 1;
            } else {
                numCnt[sums[i+1]] ++;
            }
        }
        return res;
    }
};
// @lc code=end

